//
//  Guard.cpp
//  sneakAttackGame
//
//  Created by 梁颖诗 on 2/10/24.
//  Copyright © 2024 梁颖诗. All rights reserved.
//

#include "Guard.hpp"
#include "ResourcePath.hpp"
#include <cmath>
#include<cstdlib>
#include<ctime>
#include <iostream>
Guard::Guard(float x, float y, float size, float angle, float speed)
    : position(x, y), speed(speed), size(size), angle(angle) {

        // Set the guard texture
    if (!guardTexture.loadFromFile(resourcePath() + "guardNew.png")) {
        std::cout << "there is no guard image";
        return EXIT_FAILURE;
        }
        guardSprite.setTexture(guardTexture);
        guardSprite.setScale(sf::Vector2f(0.5f, 0.5f));
        guardSprite.setPosition(position);
        
        guardSprite.setOrigin(guardSprite.getLocalBounds().width/2,guardSprite.getLocalBounds().height);

}
Guard::State state = Guard::Idle;
sf::Clock actionTimer;
float originAngle;
float finalAngle;
void Guard::chooseDirection() {
    // choose a random direction
    angle = static_cast<float>(rand() % 360);
    // rotate the guard
    guardSprite.setRotation(angle+90);
}

void Guard::autoMove(float deltaTime) {
    //some math calculation
    float radian = angle * 3.14159265f / 180.0f;
    sf::Vector2f movement(cos(radian) * speed * deltaTime, sin(radian) * speed * deltaTime);
    //std::cout << radian << "\n";
    //prevent guard from going out of the screen
    if(position.x>size && position.x <800-size && position.y >size && position.y <600-size)
        position += movement;
    else{
        position -=movement;
    }
}

void Guard::draw(sf::RenderWindow& window) {
    guardSprite.setPosition(position); // update the position
    window.draw(guardSprite);
}
void Guard::update(float deltaTime) {
    switch (state) {
        case Idle:
            //when idle, set up the timer and choose a direction
            if (actionTimer.getElapsedTime().asSeconds() >= 3) {
                state = ChoosingDirection;
                chooseDirection();
                actionTimer.restart();
            }
            break;
        case ChoosingDirection:
            state = Moving;
            break;
        case Moving:
            //smooth moving controlled by delta time
            if (actionTimer.getElapsedTime().asSeconds() < 3) {
                autoMove(deltaTime);
            } else {
                state = Idle;
                actionTimer.restart();
            }
            break;
    }
    
}
void Guard::init(float x, float y, float size, float angle, float speed){

    guardSprite.setPosition(x,y); 
    guardSprite.setRotation(angle);
    position.x = x;
    position.y = y;

}

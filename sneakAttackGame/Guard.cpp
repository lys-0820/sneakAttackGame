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

        // Set the texture
    if (!guardTexture.loadFromFile(resourcePath() + "guard.jpg")) {
        std::cout << "there is no guard image";
        return EXIT_FAILURE;
        }
        guardSprite.setTexture(guardTexture);
        guardSprite.setScale(sf::Vector2f(0.2f, 0.2f));
        guardSprite.setPosition(position);
        triArrow.setRadius(size/2);
        triArrow.setPointCount(3);    // a triangle
        triArrow.setOrigin(size/2,size/2);
        triArrow.setFillColor(sf::Color::Black);

}
Guard::State state = Guard::Idle;
sf::Clock actionTimer;
float originAngle;
float finalAngle;
void Guard::chooseDirection() {
    // choose a random direction
    angle = static_cast<float>(rand() % 360);
    triArrow.setRotation(angle);
}

void Guard::autoMove(float deltaTime) {
    // 将方向从度转换为弧度
    float radian = angle * 3.14159265f / 180.0f;
        // 计算基于方向的移动向量
    sf::Vector2f movement(cos(radian) * speed * deltaTime, sin(radian) * speed * deltaTime);
    std::cout << radian << "\n";
    if(position.x>size && position.x <800-size && position.y >size && position.y <600-size)
        position += movement;
    else{
        position -=movement;
    }
    
    triArrow.setPosition(position.x,position.y - size);
    
    triArrow.setFillColor(sf::Color::Blue);
}
//float shortestRotation(float originAngle, float angle) {
//    float diff = angle - originAngle;
//    if (diff < -180.0f) diff += 360.0f;
//    if (diff > 180.0f) diff -= 360.0f;
//    //std::cout << diff << "\n";
//    return diff;
//}
//
//void smoothRotate(sf::Sprite& sprite, float targetAngle, float deltaTime, float rotationSpeed) {
//    float currentAngle = sprite.getRotation();
//    float rotationDiff = shortestRotation(currentAngle, targetAngle);
//    //std::cout << currentAngle << "\n" << targetAngle <<"\n";
//    // 根据旋转速度和帧时间计算这一帧的旋转量
//    float rotationStep = rotationSpeed * deltaTime;
//
//    // 如果旋转差大于一帧的旋转步长，则按步长旋转；否则直接旋转到目标角度
//    if (std::abs(rotationDiff) > rotationStep) {
//        finalAngle =(rotationDiff > 0 ? 1 : -1) * rotationStep;
//
//    } else {
//        finalAngle = targetAngle;
//    }
//}
void Guard::draw(sf::RenderWindow& window) {
    guardSprite.setPosition(position); // 更新形状的位置
    
    //guardSprite.rotate(finalAngle);
    window.draw(triArrow);
    window.draw(guardSprite); // 在窗口上绘制形状
}
void Guard::update(float deltaTime) {
    switch (state) {
        case Idle:
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
            if (actionTimer.getElapsedTime().asSeconds() < 3) {
                // 计算帧时间
                float frameTime =0.01;

                // 更新精灵的旋转
                //smoothRotate(guardSprite,angle, frameTime, 1.0f);
                // 假设目标角度和旋转速度
                autoMove(deltaTime);
            } else {
                state = Idle;
                actionTimer.restart();
            }
            break;
    }
    
}
void Guard::init(float x, float y, float size, float angle, float speed){

    guardSprite.setPosition(x,y); // 设置形状的初始位置
    position.x = x;
    position.y = y;

}

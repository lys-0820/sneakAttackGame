// Player.cpp
#include "Player.hpp"
Player::Player(float x, float y, float size, float speed)
    : position(x, y), speed(speed), size(size) {
    shape.setSize(sf::Vector2f(size, size)); // set shape
    shape.setPosition(position); // set origin position
    shape.setFillColor(sf::Color::Green);
        shape.setOrigin(size/2,size/2);
    triArrow.setRadius(size/2);
    triArrow.setPointCount(3);    // a triangle for indicate the direction
        triArrow.setOrigin(size/2,size/2);
    triArrow.setFillColor(sf::Color::Black);
}

void Player::handleKeyPress(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W: moveUp(); break;
        case sf::Keyboard::S: moveDown(); break;
        case sf::Keyboard::A: moveLeft(); break;
        case sf::Keyboard::D: moveRight(); break;
        default: break;
    }
}

void Player::moveUp() {
    if(position.y>size){
        position.y -= speed;
        triArrow.setPosition(position.x,position.y - size);
        triArrow.setRotation(0);
        triArrow.setFillColor(sf::Color::Red);
    }
        
}

void Player::moveDown() {
    if(position.y<600-size){
        position.y += speed;
        triArrow.setPosition(position.x,position.y + size);
        triArrow.setRotation(180);
        triArrow.setFillColor(sf::Color::Red);
    }
        
}

void Player::moveLeft() {
    if(position.x>size){
        position.x -= speed;
        triArrow.setPosition(position.x - size,position.y);
        triArrow.setRotation(270);
        triArrow.setFillColor(sf::Color::Red);
    }
        
}

void Player::moveRight() {
    if(position.x<800-size){
        position.x += speed;
        triArrow.setPosition(position.x + size,position.y);
        triArrow.setRotation(90);
        triArrow.setFillColor(sf::Color::Red);
    }
        
}
void Player::draw(sf::RenderWindow& window) {
    shape.setPosition(position); // update the position of player cube
    window.draw(triArrow);
    window.draw(shape);
    
}

void Player::init(float x, float y, float size, float speed){
    //init the game when restart
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(x,y);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(size/2,size/2);
    position.x = x;
    position.y = y;
    triArrow.setFillColor(sf::Color::Black);
    triArrow.setOrigin(size/2,size/2);
    triArrow.setRadius(size/2);
    triArrow.setPointCount(3);
    
}

// Player.cpp
#include "Player.hpp"
Player::Player(float x, float y, float size, float speed)
    : position(x, y), speed(speed), size(size) {
    shape.setSize(sf::Vector2f(size, size)); // 设置形状的大小
    shape.setPosition(position); // 设置形状的初始位置
    shape.setFillColor(sf::Color::Green); // 设置形状的填充颜色
        shape.setOrigin(size/2,size/2);
    triArrow.setRadius(size/2);
    triArrow.setPointCount(3);    // a triangle
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
        triArrow.setFillColor(sf::Color::Blue);
    }
        
}

void Player::moveDown() {
    if(position.y<600-size){
        position.y += speed;
        triArrow.setPosition(position.x,position.y + size);
        triArrow.setRotation(180);
        triArrow.setFillColor(sf::Color::Blue);
    }
        
}

void Player::moveLeft() {
    if(position.x>size){
        position.x -= speed;
        triArrow.setPosition(position.x - size,position.y);
        triArrow.setRotation(270);
        triArrow.setFillColor(sf::Color::Blue);
    }
        
}

void Player::moveRight() {
    if(position.x<800-size){
        position.x += speed;
        triArrow.setPosition(position.x + size,position.y);
        triArrow.setRotation(90);
        triArrow.setFillColor(sf::Color::Blue);
    }
        
}
void Player::draw(sf::RenderWindow& window) {
    shape.setPosition(position); // 更新形状的位置
    //triArrow.setPosition(position);
    window.draw(triArrow);
    window.draw(shape); // 在窗口上绘制形状
    
}
bool Player::sneakAttack() {
    // sneak attack logic
    return false;
}
void Player::init(float x, float y, float size, float speed){
    shape.setSize(sf::Vector2f(size, size)); // 设置形状的大小
    shape.setPosition(x,y); // 设置形状的初始位置
    shape.setFillColor(sf::Color::Green); // 设置形状的填充颜色
    shape.setOrigin(size/2,size/2);
    position.x = x;
    position.y = y;
    triArrow.setFillColor(sf::Color::Black); // 设置形状的填充颜色
    triArrow.setOrigin(size/2,size/2);
    triArrow.setRadius(size/2);
    triArrow.setPointCount(3);
    
}

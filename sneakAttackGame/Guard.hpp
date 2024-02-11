//
//  Guard.hpp
//  sneakAttackGame
//
//  Created by 梁颖诗 on 2/10/24.
//  Copyright © 2024 梁颖诗. All rights reserved.
//

#ifndef GUARD_H
#define GUARD_H

#include <SFML/Graphics.hpp>
class Guard{
public:
    enum State {
            Idle,
            ChoosingDirection,
            Moving
        };
    sf::Vector2f position;
    float speed;
    float size;
    float angle;
    sf::Texture guardTexture;
    sf::Sprite guardSprite;
    //sf::RectangleShape shape;
    sf::FloatRect getBounds() const {
        return guardSprite.getGlobalBounds();
    }
    Guard(float x, float y, float size, float angle, float speed);
    void draw(sf::RenderWindow& window); // 绘制玩家形状的方法
    void chooseDirection();
    void rotate(float originAngle,float angle, float deltaTime);
    void autoMove(float deltaTime);
    void setTime(int time);
    void update(float deltaTime);
    void init(float x, float y, float size, float angle, float speed);
    sf::CircleShape triArrow; // an arrow
};

#endif // GUARD_H

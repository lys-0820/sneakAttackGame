//
//  Entity.hpp
//  sneakAttackGame
//
//  Created by 梁颖诗 on 2/10/24.
//  Copyright © 2024 梁颖诗. All rights reserved.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    
    Entity(float x, float y, float degree, float size, float speed);

    void move();
    void turn(float degree);
    

protected:
    sf::Vector2f position;
    float degree;
    float size;
    float speed;
    bool type;
};

#endif // ENTITY_H

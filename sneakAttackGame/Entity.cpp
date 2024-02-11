//
//  Entity.cpp
//  sneakAttackGame
//
//  Created by 梁颖诗 on 2/10/24.
//  Copyright © 2024 梁颖诗. All rights reserved.
//

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
Entity::Entity(float x, float y, float degree, float size, float speed)
    : position(x, y), degree(degree), size(size), speed(speed) {}


void Entity::turn(float degree) {
    this->degree = degree;
}

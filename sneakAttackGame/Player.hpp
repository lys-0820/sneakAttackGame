// Player.hpp
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    sf::Vector2f position;
    float speed;
    float size;
    sf::RectangleShape shape; // 代表玩家的形状
    sf::CircleShape triArrow; // an arrow

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }
    Player(float x, float y, float size, float speed);
    void handleKeyPress(sf::Keyboard::Key key);
    void draw(sf::RenderWindow& window); // 绘制玩家形状的方法
    bool sneakAttack();
    void init(float x, float y, float size, float speed);

private:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};

#endif // PLAYER_H

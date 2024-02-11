#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.hpp"
#include "Guard.hpp"

class GameManager {
public:
    GameManager();
    void gameLoop(sf::RenderWindow& window);
    void updateGameplay();
    void popUI(sf::RenderWindow& window, sf::Text text);
    float distance(Player& player, Guard& guard);
    bool isPause;
    bool isWin;
private:
    
    bool checkSneakAttack(Player& player, Guard& guard);
    bool isCollided(Player& player, Guard& guard);
};

#endif // GAMEMANAGER_H

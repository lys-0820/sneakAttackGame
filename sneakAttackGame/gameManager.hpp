#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.hpp"
#include "Guard.hpp"

class GameManager {
public:
    GameManager();
    void gameLoop();
    void updateGameplay();
    void popUI(sf::RenderWindow& window, sf::Text text);
    bool isPause;
    bool isWin;
    
private:
    
    bool checkSneakAttack(Player& player, Guard& guard);
    bool isCollided(const Player& player, const Guard& guard);
};

#endif // GAMEMANAGER_H

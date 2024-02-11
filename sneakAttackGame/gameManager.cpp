//
//
//  Created by 梁颖诗 on 2/10/24.
//  Copyright © 2024 梁颖诗. All rights reserved.
//
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "gameManager.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
using namespace std;
GameManager::GameManager() {
    // 初始化逻辑
    isPause = false;
    isWin = false;
    
}

void GameManager::gameLoop() {
    // 游戏主循环逻辑
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sneak Attack Game");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "tuffy.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("sneak attack", font, 50);
    text.setFillColor(sf::Color::White);
    Player player(400, 300, 20, 30); // init player
    
    Guard guard(300,400,40,290,0.1); // init guard
    // Start the game loop
    while (window.isOpen())
        {
            
            // Process events
            sf::Event event;
            while (window.pollEvent(event)) {
                // close window: exit
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                
            if(!isPause){
                /* -----------gameplay part------------------- */
                // guard auto move delta time
                guard.update(2.0);
                //collision test
                if(isCollided(player,guard)){
                    //player is killed by the guard
                    isWin = false;
                    isPause = true;
                }
                // handle keyboard input
                if (event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::Q){
                        //begin sneak attack
                        bool isSuccess = checkSneakAttack(player, guard);
                        if(isSuccess){
                            isWin = true;
                            isPause = true;
                            }
                        else{
                            text.setString("You are too far from the guard!");
                            }
                        }
                    else{
                        player.handleKeyPress(event.key.code);
                        }
                }
                /* -----------render part------------------- */
                window.clear();
                // draw player and guard
                player.draw(window);
                guard.draw(window);
                // Draw the string
                window.draw(text);
                // Update the window
                window.display();
                
            }
            else{
                /* -----------game is paused------------------- */
                if(isWin){
                    text.setString("You won! \n Press R to restart.");
                    }
                else{
                    text.setString("You lost!\n Press R to restart.");
                    
                    }
                popUI(window,text);
                if (event.type == sf::Event::KeyPressed) {
                    if(event.key.code == sf::Keyboard::R){
                        isPause = false;
                        player.init(400, 300, 20, 30);
                        guard.init(400,400,40,290,10);
                        text.setString("sneak attack");
                    }
                }
            }
        }
        
    }

    return EXIT_SUCCESS;
}
bool GameManager::isCollided(const Player& a, const Guard& b) {
    return a.getBounds().intersects(b.getBounds());
}
float distance(Player& player, Guard& guard) {
    sf::FloatRect bounds = guard.getBounds();
    float width = bounds.width;
    float height = bounds.height;
    float deltaX = std::abs(player.position.x - (bounds.left + 0.5 * width));
    float deltaY = std::abs(player.position.y - (height+bounds.top));
    float deltaDis = std::sqrt(pow(deltaX, 2)+pow(deltaY,2));
    //cout << deltaX <<"\n" << deltaY<< "\n";
    if(deltaDis>0.7*player.size)
        deltaDis -= 0.7*player.size;
    return deltaDis;
}
bool GameManager::checkSneakAttack(Player& player, Guard& guard) {
    // check if attack succeeds
    sf::Vector2f position1 = player.position;
    sf::Vector2f position2 = guard.position;

    float dist = distance(player, guard);
    
    //cout << dist <<"\n" << height<< "\n";
    //cout << dist << "\n";

    if(dist<(guard.getBounds().height/2)){
        return true;
    }
    return false;
}
void GameManager::popUI(sf::RenderWindow& window,sf::Text text){
    window.clear();
    // Draw the string
    window.draw(text);
    // Update the window
    window.display();

}

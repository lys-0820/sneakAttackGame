
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "gameManager.hpp"
int main(int, char const**)
{
    
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sneak Attack Game");
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "tuffy.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Sneak Attack Game \nPress any button to start", font, 30);
    text.setOrigin(text.getLocalBounds().width/2,text.getLocalBounds().height/2);
    text.setPosition(400,300);
    text.setFillColor(sf::Color::White);
    while (window.isOpen())
        {
            window.clear();
            // Draw the string
            window.draw(text);
            // Update the window
            window.display();
            // Process events
            sf::Event event;
            while (window.pollEvent(event)) {
                // close window: exit
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                // handle keyboard input
                if (event.type == sf::Event::KeyPressed) {
                    // Load a music to play
                    sf::Music music;
                    if (!music.openFromFile(resourcePath() + "doodle_pop.ogg")) {
                        return EXIT_FAILURE;
                    }

                    // Play the music
                    music.play();
                    music.setLoop(1);
                    GameManager gameManager;
                    gameManager.gameLoop(window);
                }
            }
        }

    return EXIT_SUCCESS;

}


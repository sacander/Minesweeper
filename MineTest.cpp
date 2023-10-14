// Tests general behaviour of the Mine class.
// All functions of Mine must be manually tested.
// Creates game window for this purpose with test tiles.

#include "Mine.h"
#include "Minesweeper.h"
#include <iostream>

int main() {
    // Creates test game instance and window
    Minesweeper game(500, "Dummy Game");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Entity Test");
    // First mine clicked should not be shown
    // Should not be clickable when flagged or shown
    Mine testMine1(Vector2f(100, 100), game, 0, 0);
    Mine testMine2(Vector2f(150, 100), game, 0, 0);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                testMine1.onClickEvent(&window, event);
                testMine2.onClickEvent(&window, event);
            }
        }

        window.clear();
        testMine1.draw(&window);
        testMine2.draw(&window);
        window.display();
    }

    return 0;
}
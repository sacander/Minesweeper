// Tests general behaviour of the Tile class.
// All functions of Tile must be manually tested.
// Creates game window for this purpose with test tiles.

#include "Tile.h"
#include "Minesweeper.h"
#include <iostream>

int main() {
    // Creates test game instance and window
    Minesweeper game(500, "Dummy Game");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Entity Test");
    Tile testTile1(Vector2f(300, 150), game, "textures/1.png", 5, 5);
    // Tests that error is logged if filepath does not exist
    Tile testTile2(Vector2f(300, 300), game, "", 0, 0);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                // Tests showTile on left click and toggleFlag on right click
                // Need to test:
                // Right click toggles the flag
                // Left click does nothing when flagged
                // Left click on blank tile reveals it
                // Shown tile cannot be flagged or rehidden
                testTile1.onClickEvent(&window, event);
                testTile2.onClickEvent(&window, event);
            }
        }

        window.clear();
        testTile1.draw(&window);
        testTile2.draw(&window);
        window.display();
    }

    return 0;
}
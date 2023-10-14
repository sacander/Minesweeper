// Tests general behaviour of the Number class.
// All functions of Number must be manually tested.
// Creates game window for this purpose with test tiles.

#include "Number.h"
#include "Minesweeper.h"
#include <iostream>

int main() {
    // Creates test game instance and window
    Minesweeper game(500, "Dummy Game");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Entity Test");
    // Tests each value, in addition to an invalid value
    // When clicked, should reveal respective numbers, and print increment tiles
    // 0 tile should also print reveal adjacent tiles
    Number testNumber0(Vector2f(100, 100), game, 0, 0, 0);
    Number testNumber1(Vector2f(120, 100), game, 0, 0, 1);
    Number testNumber2(Vector2f(140, 100), game, 0, 0, 2);
    Number testNumber3(Vector2f(160, 100), game, 0, 0, 3);
    Number testNumber4(Vector2f(180, 100), game, 0, 0, 4);
    Number testNumber5(Vector2f(200, 100), game, 0, 0, 5);
    Number testNumber6(Vector2f(220, 100), game, 0, 0, 6);
    Number testNumber7(Vector2f(240, 100), game, 0, 0, 7);
    Number testNumber8(Vector2f(260, 100), game, 0, 0, 8);
    Number testNumber9(Vector2f(280, 100), game, 0, 0, 9);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                testNumber0.onClickEvent(&window, event);
                testNumber1.onClickEvent(&window, event);
                testNumber2.onClickEvent(&window, event);
                testNumber3.onClickEvent(&window, event);
                testNumber4.onClickEvent(&window, event);
                testNumber5.onClickEvent(&window, event);
                testNumber6.onClickEvent(&window, event);
                testNumber7.onClickEvent(&window, event);
                testNumber8.onClickEvent(&window, event);
                testNumber9.onClickEvent(&window, event);
            }
        }

        window.clear();
        testNumber0.draw(&window);
        testNumber1.draw(&window);
        testNumber2.draw(&window);
        testNumber3.draw(&window);
        testNumber4.draw(&window);
        testNumber5.draw(&window);
        testNumber6.draw(&window);
        testNumber7.draw(&window);
        testNumber8.draw(&window);
        testNumber9.draw(&window);
        window.display();
    }

    return 0;
}
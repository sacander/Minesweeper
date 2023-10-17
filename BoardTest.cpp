#include <iostream>
#include <unistd.h>

#include "Board.h"
#include "Minesweeper.h"

// Board Test Function

int main() {
    // Creates test game instance and window
    Minesweeper game(500, "Dummy Game");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Entity Test");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}

class BoardTest {
    private:
        Minesweeper *game;

        void testGrid();
        void testRevealMines();
        void testAdjTiles();
        void testGenerateBoard();
        void testIncrementRevealedTiles();

    public:
        void runTests() {
        }
        BoardTest(/* args */);
        ~BoardTest();
};

void BoardTest::testGrid() {
}

void BoardTest::testRevealMines() {
}

void BoardTest::testAdjTiles() {
}

void BoardTest::testGenerateBoard() {
}

// Tests incrementRevealedTiles() method
void BoardTest::testIncrementRevealedTiles() {

    // Generate a board 5x5, 2 mines
    game->newBoard(5, 5, 2);
}

BoardTest::BoardTest(/* args */) {
}

BoardTest::~BoardTest() {
}

#include <iostream>
#include <unistd.h>

#include "Board.h"
#include "Minesweeper.h"

// Board Test Function

using namespace std;

class BoardTest {
    private:
        Minesweeper *game;
        sf::RenderWindow *window;
        void testAdjTiles();
        void testGenerateBoard(sf::RenderWindow *window);
        void testIncrementRevealedTiles();

    public:
        void runTests() {
            testGenerateBoard(window);
            testIncrementRevealedTiles();
        }
        BoardTest(Minesweeper *game, sf::RenderWindow *window);
        ~BoardTest();
};

// Testing making a variety of grid sizes works
void BoardTest::testGenerateBoard(sf::RenderWindow *window) {
    // Just going through a few grid sizes to check (visually) it works
    cout << "Board 1" << endl;
    game->newBoard(5, 5, 2);
    window->clear();
    game->getBoard()->draw(window);
    window->display();
    sleep(1);
    cout << "Board 2" << endl;
    game->newBoard(8, 8, 2);
    window->clear();
    game->getBoard()->draw(window);
    window->display();
    sleep(1);
    cout << "Board 3" << endl;
    game->newBoard(14, 14, 2);
    window->clear();
    game->getBoard()->draw(window);
    window->display();
    sleep(1);
    cout << "Board 4" << endl;
    game->newBoard(26, 26, 2);
    window->clear();
    game->getBoard()->draw(window);
    window->display();
    sleep(1);
    cout << "Board 5" << endl;
    game->newBoard(5, 8, 2);
    window->clear();
    game->getBoard()->draw(window);
    window->display();
    sleep(1);
    cout << "Board 6" << endl;
    game->newBoard(12, 5, 2);
    window->clear();
    game->getBoard()->draw(window);
    window->display();
}

// Tests incrementRevealedTiles() method works on a variety of board sizes
void BoardTest::testIncrementRevealedTiles() {

    cout << "incrementTiles Test BEGIN" << endl;

    // Generate a board 5x5, 2 mines
    cout << "Testing Increment on 5x5 Board with 2 Mines" << endl;
    game->newBoard(5, 5, 2);
    for (int i = 0; i < 22; i++) {
        if (game->getBoard()->incrementRevealedTiles()) {
            cout << "Test 2 FAIL" << endl;
        }
    }
    if (game->getBoard()->incrementRevealedTiles()) {
        cout << "Test 2 PASS" << endl;
    }

    // Generate a board 8x8, 16 mines
    cout << "Testing Increment on 8x8 Board with 16 Mines" << endl;
    game->newBoard(8, 8, 16);
    for (int i = 0; i < 47; i++) {
        if (game->getBoard()->incrementRevealedTiles()) {
            cout << "Test 2 FAIL" << endl;
        }
    }
    if (game->getBoard()->incrementRevealedTiles()) {
        cout << "Test 2 PASS" << endl;
    }

    // Generate a board 26x26, 50 mines
    cout << "Testing Increment on 26x26 Board with 50 Mines" << endl;
    game->newBoard(26, 26, 50);
    for (int i = 0; i < 625; i++) {
        if (game->getBoard()->incrementRevealedTiles()) {
            cout << "Test 3 FAIL" << endl;
        }
    }
    if (game->getBoard()->incrementRevealedTiles()) {
        cout << "Test 3 PASS" << endl;
    }

    // Test on a non-square board
    cout << "Testing Increment on 5x8 board with 5 mines [NON square board]" << endl;
    game->newBoard(5, 8, 5);
    for (int i = 0; i < 34; i++) {
        if (game->getBoard()->incrementRevealedTiles()) {
            cout << "Test 4 FAIL" << endl;
        }
    }
    if (game->getBoard()->incrementRevealedTiles()) {
        cout << "Test 4 PASS" << endl;
    }

    // Test method after loading a game (to see if tiles are preserved)
    cout << "Testing Increment on a loaded board" << endl;
    int **boardTest = new int *[8 + 2];
    for (int i = 0; i < 8 + 2; i++) {
        boardTest[i] = new int[8 + 2]{};
    }
    // Add two mines to board
    boardTest[3][3] = 9;
    boardTest[4][4] = 10;
    game->getBoard()->loadBoard(boardTest, 10, 10, game);
    for (int i = 0; i < 61; i++) {
        if (game->getBoard()->incrementRevealedTiles()) {
            cout << "Test 5 FAIL" << endl;
        }
    }
    if (game->getBoard()->incrementRevealedTiles()) {
        cout << "Test 5 PASS" << endl;
    }

    cout << "incrementTiles Test DONE" << endl;
}

BoardTest::BoardTest(Minesweeper *gamen, sf::RenderWindow *windown) {
    window = windown;
    game = gamen;
}

BoardTest::~BoardTest() {
    delete game;
}

int main() {
    // Creates test game instance and window
    Minesweeper game(500, "Dummy Game");
    sf::RenderWindow window(sf::VideoMode(500, 500), "Board Test");
    BoardTest testEnv(&game, &window);
    cout << "Click on Board Test to run through tests" << endl;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                testEnv.runTests();
            }
        }
        window.clear();
        window.display();
    }

    return 0;
}

#include "Minesweeper.h"
#include <iostream>

Minesweeper::Minesweeper(int size, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(size, size), title);
    timer = new Timer(Vector2f(357.9, 15), (*this));
    gameActive = true;
}

Minesweeper::~Minesweeper() {
    delete window;
    delete timer;
}

void Minesweeper::run() {
    //Number test(Vector2f(50, 50), *this, 0, 0, 5);
    //test.showTile();
   // Mine test1(Vector2f(66, 50), *this, 0, 0);
    NewGameButton newIcon(Vector2f(60, 15), *this);
    SaveButton saveIcon(Vector2f(159.3, 15), *this);
    LoadButton loadIcon(Vector2f(258.6, 15), *this);

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                //test.onClickEvent(window, event);
                //test1.onClickEvent(window, event);
                if (gameActive) board->onClickEvent(window, event);
                newIcon.onClickEvent(window, event);
                loadIcon.onClickEvent(window, event);
                saveIcon.onClickEvent(window, event);
            }
        }

        window->clear();
       // test.draw(window);
       // test1.draw(window);
        board->draw(window);
        timer->draw(window);
        newIcon.draw(window);
        saveIcon.draw(window);
        loadIcon.draw(window);
        window->display();
    }
}

void Minesweeper::gameWin() {
    gameActive = false;
    timer->stopTimer();
}

//stop timer, show all mines
void Minesweeper::gameLose(Tile* mine) {

    if(gameActive){
        //Make it so you cant reveal tiles
        gameActive = false;
        std::cout << "end game" << std::endl;
        timer->stopTimer();
        board->revealMines(mine);
    }
}

Board* Minesweeper::newBoard(int height, int width, int mines) {
    if(newGame) delete board;
    board = new Board(height, width, mines, this);
    gameActive = true;
    newGame = true;
    return board;
}

Board *Minesweeper::getBoard() {
    return board;
}

Timer *Minesweeper::getTimer() {
    return timer;
}
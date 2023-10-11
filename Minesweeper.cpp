#include "Minesweeper.h"

Minesweeper::Minesweeper(int size, std::string title) {
    window = new sf::RenderWindow(sf::VideoMode(size, size), title);
}

Minesweeper::~Minesweeper() {
    delete window;
}

void Minesweeper::run() {
    Tile test("./textures/tile.png", Vector2f(50, 50), *this, "./textures/mine.png", 0, 0);

    while (window->isOpen()) {
        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                test.onClickEvent(window, event);
            }
        }

        window->clear();
        test.draw(window);
        window->display();
    }
}

void Minesweeper::gameWin() {}

//stop timer, show all mines
void Minesweeper::gameLose() {

    timer->stopTimer();
    board->revealMines();

    //Make it so you cant reveal tiles??

}

Board *Minesweeper::getBoard() {
    return board;
}

Timer *Minesweeper::getTimer() {
    return timer;
}

int main() {
    Minesweeper minesweeper(500, "Minesweeper");
    minesweeper.run();

    return 0;
}
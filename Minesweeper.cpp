#include "Minesweeper.h"

Minesweeper::Minesweeper(int size, std::string title) {
    window = new RenderWindow(VideoMode(size, size), title);
}

void Minesweeper::run() {

    while (window->isOpen()) {
        Event event;

        while (window->pollEvent(event)) {

            if (event.type == Event::Closed) {
                window->close();
            }

        }

        window->clear();
        window->display();
    }

}

int main() {
    Minesweeper minesweeper(500, "Minesweeper");
    minesweeper.run();

    return 0;
}
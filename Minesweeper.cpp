#include "Minesweeper.h"
#include "Tile.h"

Minesweeper::Minesweeper(int size, std::string title) {
    window = new RenderWindow(VideoMode(size, size), title);
}

Minesweeper::~Minesweeper() {
    delete window;
}

void Minesweeper::run() {
    Tile test("test.png", "testflag.png", "testhidden.png", 0, 0);

    while (window->isOpen()) {
        Event event;

        while (window->pollEvent(event)) {

            if (event.type == Event::Closed) {
                window->close();
            }

            if (event.type == Event::MouseButtonPressed) {
                test.onClickEvent(window, event);
            }
        }

        window->clear();
        test.draw(window);
        window->display();
    }
}

int main() {
    Minesweeper minesweeper(500, "Minesweeper");
    minesweeper.run();

    return 0;
}
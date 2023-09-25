#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Minesweeper {
private:
    RenderWindow *window;

public:
    Minesweeper(int size, std::string title);
    void run();
};

#endif
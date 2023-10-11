#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "Board.h"
#include "Timer.h"
#include "Mine.h"
#include "Number.h"
#include "NewGameButton.h"
#include <SFML/Graphics.hpp>

class Minesweeper {
    private:
        sf::RenderWindow *window;
        Board *board;
        Timer *timer;
        bool gameActive;
    public:
        Minesweeper(int size, std::string title);
        ~Minesweeper();
        void run();
        void gameWin();
        void gameLose();
        Board *getBoard();
        Timer *getTimer();
        void newBoard(int height, int width, int mines);
};

#endif
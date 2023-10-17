#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "Board.h"
#include "LoadButton.h"
#include "Mine.h"
#include "NewGameButton.h"
#include "Number.h"
#include "SaveButton.h"
#include "Timer.h"
#include <SFML/Graphics.hpp>

class Minesweeper {
    private:
        sf::RenderWindow *window;
        Board *board;
        Timer *timer;
        bool newGame = false;
        bool gameActive;

    public:
        Minesweeper(int size, std::string title);
        ~Minesweeper();
        void run();
        void gameWin();
        void setGameActive(bool gameActiven);
        void gameLose(Tile *mine);
        Board *getBoard();
        Timer *getTimer();
        Board *newBoard(int height, int width, int mines);
        bool getGameActive();
};

#endif
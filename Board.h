#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Mine.h"
#include "Number.h"

using namespace sf;

class Board {
    private:
        //2D array containing the numbers / mines (tiles)
        Tile ** *tiles;
        int ** saveBoard;
        int xSize;
        int ySize;
        int boardX = 50;
        int boardY = 50;
        int firstSafeX;
        int firstSafeY;
        bool swappedTiles = false;
        int totalMines;
        int revealedTiles = 0;
    public:
        Board(int width, int height, int mines, Minesweeper* game);
        int** getSaveBoard();
        void draw(RenderWindow *window);
        void onClickEvent(RenderWindow *window, Event event);
        bool incrementRevealedTiles();
        void swapTiles(int x, int y);
        void revealMines(Tile* tile);
        std::vector<Tile *> getAdjacentTiles(int x, int y);
        int getRevealedTiles();
        int getSizeX();
        int getSizeY();
        ~Board();
};

#endif
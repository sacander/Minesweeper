#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"

using namespace sf;

class Board {
    private:
        Tile * tiles;
        int xSize;
        int ySize;
        int totalMines;
        int revealedTiles = 0;

    public:
        bool incrementRevealedTiles();
        void swapTiles(int x, int y);
        Tile **getAdjacentTiles();
        int getRevealedTiles();
};

#endif
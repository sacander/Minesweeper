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
        // int firstSafeX;
        // int firstSafeY;
        bool loading = false;
        int totalMines;
        int revealedTiles = 0;
        void cleanTiles(int height, int width);
    public:
        Board(int width, int height, int mines, Minesweeper* game, int clickX, int clickY);
        void loadBoard(int ** board, int width, int height, Minesweeper * game);
        void generateBoard(Minesweeper * game, int clickX, int clickY, int ** board);
        int** getSaveBoard();
        void draw(RenderWindow *window);
        void onClickEvent(RenderWindow *window, Event event);
        bool incrementRevealedTiles(int clickX, int clickY);
        // void swapTiles(int x, int y, Minesweeper * game);
        void revealMines(Tile* tile);
        std::vector<Tile *> getAdjacentTiles(int x, int y);
        int getRevealedTiles();
        int getSizeX();
        int getSizeY();
        ~Board();
};

#endif
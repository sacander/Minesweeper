#ifndef MINE_H
#define MINE_H

#include "Tile.h"

class Mine : public Tile {
    private:
        // Override firstTileClicked()
        bool firstTileClicked();

    public:
        Mine(std::string textureFilepath, std::string flagTextureFilepath, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos, Minesweeper &game);
        ~Mine();
        // Override showTile()
        void showTile();
};

#endif
#ifndef MINE_H
#define MINE_H

#include "Tile.h"

class Mine : public Tile {
    private:
        // Override firstTileClicked()
        bool firstTileClicked();

    public:
        Mine(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos);
        ~Mine();
        // Override showTile()
        void showTile();
};

#endif
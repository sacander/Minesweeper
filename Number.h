#ifndef NUMBER_H
#define NUMBER_H

#include "Tile.h"

class Number : public Tile {
    private:
        // Stores number of surrounding mines
        int value;

    public:
        Number(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos, int value);
        ~Number();
        // Override showTile() to extend behaviour
        void showTile();
};

#endif
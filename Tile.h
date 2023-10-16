#ifndef TILE_H
#define TILE_H

#include "Entity.h"
// class Minesweeper;
// #include <SFML/Graphics.hpp>

class Tile : public Entity {
    private:
        // Implement onClick functions so class is no longer abstract
        void onLeftClick();
        void onRightClick();
        // Checks if this is the first tile and returns this value, in addition to starting timer and generating board
        virtual bool firstTileClicked();

    protected:
        // State of tile
        bool shown = false;
        bool flag = false;
        // Alternative file textures
        sf::Texture flagTexture;
        sf::Texture hiddenTexture;
        // Tile position in board
        int xBoardPos;
        int yBoardPos;

    public:
        Tile(sf::Vector2f pos, Minesweeper &game, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos);
        ~Tile();
        // Left click shows tile, and can also be called from board after a swap
        virtual void showTile();
        // Right click toggles flag
        void toggleFlag();
};

#endif
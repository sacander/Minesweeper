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
        // Right click toggles flag
        void toggleFlag();
        // Starts timer when the first tile is clicked
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
        Tile(std::string textureFilepath, std::string flagTextureFilepath, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos, Minesweeper &game);
        ~Tile();
        // Left click shows tile, and can also be called from board after a swap
        virtual void showTile();
};

#endif
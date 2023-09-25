#ifndef TILE_H
#define TILE_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile : public Entity {
    private:
        bool shown = false;
        bool flag = false;
        Texture flagTexture;
        Texture hiddenTexture;
        int xBoardPos;
        int yBoardPos;
        void showTile();
        void toggleFlag();
        void onLeftClick();
        void onRightClick();

    public:
        Tile(std::string textureFilepath, std::string flagTextureFilepath, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos);
        ~Tile();
};

#endif
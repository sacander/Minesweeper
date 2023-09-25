#include "Tile.h"
#include <iostream>

Tile::Tile(std::string textureFilepath, std::string flagTextureFilepath, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos)
    : Entity(textureFilepath), xBoardPos(xBoardPos), yBoardPos(yBoardPos) {
    if (!flagTexture.loadFromFile(flagTextureFilepath)) {
        std::cout << "Flag texture not found" << std::endl;
    }

    if (!hiddenTexture.loadFromFile(hiddenTextureFilepath)) {
        std::cout << "Hidden texture not found" << std::endl;
    }
}

Tile::~Tile() {}

void Tile::showTile() {
    sprite.setTexture(hiddenTexture);
    shown = true;
}

void Tile::toggleFlag() {
    if (shown) {
        return;
    }
    if (flag) {
        sprite.setTexture(texture);
        flag = false;
    } else {
        sprite.setTexture(flagTexture);
        flag = true;
    }
}

void Tile::onLeftClick() {
    showTile();
}

void Tile::onRightClick() {
    toggleFlag();
}
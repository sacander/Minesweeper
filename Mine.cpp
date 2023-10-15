#include "Mine.h"
#include "Minesweeper.h"
#include <iostream>

// Constructor just calls tile constructor
Mine::Mine(sf::Vector2f pos, Minesweeper &game, int xBoardPos, int yBoardPos)
    : Tile(pos, game, "textures/mine.png", xBoardPos, yBoardPos) {}

// No memory cleaning neccessary
Mine::~Mine() {}

// Overrides behaviour of firstTileClicked()
bool Mine::firstTileClicked() {
    if (game.getBoard()->getRevealedTiles() == 0) {
        game.getTimer()->startTimer();
        std::cout << "swap tiles" << std::endl;
        game.getBoard()->swapTiles(xBoardPos, yBoardPos, &game);
        return true;
    }
    return false;
}

// Overrides behaviour of showTile()
void Mine::showTile() {
    if (!flag && !shown) {
        // Only shows tile and ends game if it is not the first tile
        if (!firstTileClicked()) {
            sprite.setTexture(hiddenTexture);
            shown = true;
            game.gameLose(this);
        }
    }
}
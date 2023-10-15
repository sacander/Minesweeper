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
        return true; // Swapped mine
    }
    return false; // No swapped mine
}

// Overrides behaviour of showTile()
void Mine::showTile() {
    // Only shows tile and ends game if a mine was not swapped
    if (!firstTileClicked() && !flag) {
        sprite.setTexture(hiddenTexture);
        shown = true;
        game.gameLose(this);
    }
}
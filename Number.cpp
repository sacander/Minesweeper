#include "Number.h"
#include "Minesweeper.h"

// Constructor calls tile constructor and assigns the value
Number::Number(std::string textureFilepath, sf::Vector2f pos, Minesweeper &game, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos, int value)
    : Tile(textureFilepath, pos, game, hiddenTextureFilepath, xBoardPos, yBoardPos), value(value) {}

// No memory cleaning neccessary
Number::~Number() {}

// Extends behaviour of showTile()
void Number::showTile() {
    // Keeps general behaviour
    Tile::showTile();
    // Shows neighbouring tiles if it has a value of 0.
    if (value == 0) {
        Tile **adjacentTiles = game.getBoard()->getAdjacentTiles();
        for (int i = 0; i < 8; i++) {
            adjacentTiles[i]->showTile();
        }
    }
    // Checks if game has been won
    if (game.getBoard()->incrementRevealedTiles()) {
        game.gameWin();
    }
}
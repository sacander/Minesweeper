#include "Tile.h"
#include "Minesweeper.h"
#include <iostream>

// Constructor sets textures and prints errors if not found
Tile::Tile(sf::Vector2f pos, Minesweeper &game, std::string hiddenTextureFilepath, int xBoardPos, int yBoardPos)
    : Entity("textures/tile.png", pos, game), xBoardPos(xBoardPos), yBoardPos(yBoardPos) {
    if (!flagTexture.loadFromFile("textures/flag.png")) {
        std::cout << "Flag texture not found" << std::endl;
    }

    if (!hiddenTexture.loadFromFile(hiddenTextureFilepath)) {
        std::cout << "Hidden texture not found" << std::endl;
    }
}

// No memory cleaning neccessary
Tile::~Tile() {}

// Tiles are revealed when left-clicked
void Tile::onLeftClick() {
    showTile();
}

// Flags are toggled when right-clicked
void Tile::onRightClick() {
    toggleFlag();
}

// Behaviour for toggling the flag
void Tile::toggleFlag() {
    // Flag cannot be toggled if tile is revealed or if no tiles are revealed
    if (shown || game.getBoard()->getRevealedTiles() == 0) {
        return;
    }
    // Hide flag if already flagged

    int **saveBoard = game.getBoard()->getSaveBoard();
    
    if (flag) {
        sprite.setTexture(texture);
        // Writes flag to save board
        saveBoard[yBoardPos][xBoardPos] = -1 * saveBoard[yBoardPos][xBoardPos];
        flag = false;
    } else {
        // Show flag if not already flagged
        sprite.setTexture(flagTexture);
        // Removes flag from save board
        saveBoard[yBoardPos][xBoardPos] = -1 * saveBoard[yBoardPos][xBoardPos];
        flag = true;
    }
}

// Checks if it is the first tile and starts the timer
bool Tile::firstTileClicked() {
    if (game.getBoard()->getRevealedTiles() == 0) {
        game.getTimer()->resetTimer();
        game.getTimer()->startTimer();
        return true;
    }
    return false;
}

// Calls firstTileClicked() then shows hidden sprite and updates shown status
void Tile::showTile() {
    // Only does anything if not flagged and not already shown
    if (!flag && !shown) {
        sprite.setTexture(hiddenTexture);
        shown = true;
    }
}
#include "Number.h"
#include "Minesweeper.h"
#include <vector>
#include <iostream>

// Constructor calls tile constructor and assigns the value
Number::Number(sf::Vector2f pos, Minesweeper &game, int xBoardPos, int yBoardPos, int value)
    : Tile(pos, game, "textures/" + std::to_string(value) + ".png", xBoardPos, yBoardPos), value(value) {}

// No memory cleaning neccessary
Number::~Number() {}

// Extends behaviour of showTile()
void Number::showTile() {
    if(!shown){    
        // Keeps general behaviour
        if (!flag){
            Tile::showTile();
        }
        // Shows neighbouring tiles if it has a value of 0.
        if (value == 0) {
            std::vector<Tile *> adjacentTiles = game.getBoard()->getAdjacentTiles(xBoardPos, yBoardPos);
            int length = adjacentTiles.size();
            std::cout << length << " length" << std::endl;
            for (int i = 0; i < length; i++) {
                adjacentTiles.at(i)->showTile();
            }
        }
        // Checks if game has been won
        if (game.getBoard()->incrementRevealedTiles()) {
            game.gameWin();
        }
    }
}
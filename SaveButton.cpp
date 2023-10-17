#include "SaveButton.h"

#include <ctime>
#include <fstream>
#include <iostream>

#include "Minesweeper.h"

// constructor
SaveButton::SaveButton(Vector2f pos, Minesweeper &game)
    : Entity("./textures/save.png", pos, game) {}

// deconstructor
SaveButton::~SaveButton() {}

// calls saveGame() if the game is in progress (does not allow a game that has
// not started or one that has ended to be saved)
void SaveButton::onLeftClick() {
    // if tiles have been revealed and the game is active allow save
    if (game.getBoard()->getRevealedTiles() != 0 &&
        game.getGameActive() == true) {
        std::cout << "saving..." << std::endl;
        saveGame();
    } else if (game.getGameActive()) {
        std::cout << "Cannot save a game that has not commenced" << std::endl;
    } else {
        std::cout << "Cannot save a completed game" << std::endl;
    }
}

// calls saveGame() if the game is in progress (does not allow a game that has
// not started or one that has ended to be saved)
void SaveButton::onRightClick() {
    // if tiles have been revealed and the game is active allow save
    if (game.getBoard()->getRevealedTiles() != 0 &&
        game.getGameActive() == true) {
        std::cout << "saving..." << std::endl;
        saveGame();
    } else if (game.getGameActive()) {
        std::cout << "Cannot save a game that has not commenced" << std::endl;
    } else {
        std::cout << "Cannot save a completed game" << std::endl;
    }
}

void SaveButton::saveGame() {
    // saving
    std::ofstream saveFile;
    saveFile.open("progress.csv");

    // between values = , new row = /n

    // timer
    saveFile << game.getTimer()->getGameTime();
    saveFile << "\n";

    // array
    int **boardArray = game.getBoard()->getSaveBoard();

    // getting size of array
    int length = game.getBoard()->getSizeY() + 2;
    // std::cout << length << std::endl;
    int width = game.getBoard()->getSizeX() + 2;
    // std::cout << width << std::endl;

    // std::cout << length << " " << width << std::endl;

    // save length and width
    saveFile << length << ",";
    saveFile << width << "\n";

    // save the board array
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            saveFile << boardArray[i][j] << ",";
            // std::cout << boardArray[i][j];
        }
        saveFile << "\n";
        // std::cout << std::endl;
    }

    saveFile.close();
}
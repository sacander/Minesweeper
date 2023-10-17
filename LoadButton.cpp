#include "LoadButton.h"

#include <fstream>
#include <iostream>

#include "Minesweeper.h"

// constructor for the load button class
LoadButton::LoadButton(Vector2f pos, Minesweeper &game)
    : Entity("./textures/load.png", pos, game) {}

// deconstructor
LoadButton::~LoadButton() {}

// function run when left click occurs, calls load game
void LoadButton::onLeftClick() { loadGame(); }

// function run when right click occurs, calls load game
void LoadButton::onRightClick() { loadGame(); }

// function to read in data from save file
void LoadButton::loadGame() {
    // load from a file
    std::string dataLine;
    std::ifstream saveFile("progress.csv");

    // initialise values
    int elapsedTime = 0;
    int length = 0;
    int width = 0;

    // open save file to read in info
    if (saveFile.is_open()) {
        // get timer info
        std::getline(saveFile, dataLine, '\n');
        elapsedTime = stoi(dataLine);
        // std::cout << elapsedTime << std::endl;

        // get length and width
        std::getline(saveFile, dataLine, ',');
        length = stoi(dataLine);

        std::getline(saveFile, dataLine, '\n');
        width = stoi(dataLine);

        // create the array using length and width
        int **boardArray = new int *[length];
        for (int i = 0; i < length; i++) {
            boardArray[i] = new int[width]{};
        }

        // read info into array
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                std::getline(saveFile, dataLine, ',');
                boardArray[i][j] = stoi(dataLine);
            }
        }

        // for (int i = 0; i < length; i++){
        //     for (int j = 0; j < width; j++) {
        //         std::cout << boardArray[i][j] << " ";
        //     }
        // std::cout << std::endl;
        // }

        // set game time to previous save's timer
        game.getTimer()->startTimer();
        game.getTimer()->setInitialTime(time(0) - elapsedTime);

        // call loadBoard() function
        game.getBoard()->loadBoard(boardArray, width, length, &game);
    }
    saveFile.close();
}
#include "LoadButton.h"
#include "Minesweeper.h"
#include <fstream>
#include <iostream>

LoadButton::LoadButton(Vector2f pos, Minesweeper &game)
: Entity("./textures/load.png", pos, game) {}

LoadButton::~LoadButton() {}

void LoadButton::onLeftClick() {
    loadGame();
}

void LoadButton::onRightClick() {
    loadGame();
}

void LoadButton::loadGame() {
    //load from a file 
    std::string dataLine;
    std::ifstream saveFile("progress.csv");

    //initialise values 
    int elapsedTime = 0;
    int length = 0;
    int width = 0;

    if (saveFile.is_open()){
        //get timer info
        std::getline(saveFile, dataLine, '\n');
        elapsedTime = stoi(dataLine);
        //std::cout << elapsedTime << std::endl;

        //get length and width
        std::getline(saveFile, dataLine, ',');
        length = stoi(dataLine);

        std::getline(saveFile, dataLine, '\n');
        width = stoi(dataLine);

        //create the array using length and width
        int **boardArray = new int*[length];
        for (int i = 0; i < length; i++) {
            boardArray[i] = new int[width]{};
        }

        //read info into array
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                std::getline(saveFile, dataLine, ',');
                boardArray[i][j] = stoi(dataLine);
            }
        }

        for (int i = 0; i < length; i++){
            for (int j = 0; j < width; j++) {
                std::cout << boardArray[i][j] << " ";
            }
        std::cout << std::endl;
        }

        //set game time to previous save's timer
        game.getTimer()->resetTimer();
        game.getTimer()->setInitialTime(time(0)-elapsedTime);

        //call load board function
        game.getBoard()->loadBoard(boardArray, width, length, &game);
    }
    saveFile.close();
}
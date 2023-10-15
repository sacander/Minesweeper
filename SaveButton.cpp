#include "SaveButton.h"
#include "Minesweeper.h"
#include <fstream>
#include <iostream>
#include <ctime>

SaveButton::SaveButton(Vector2f pos, Minesweeper &game)
: Entity("./textures/save.png", pos, game) {}

SaveButton::~SaveButton() {}

void SaveButton::onLeftClick() {
    saveGame();
}

void SaveButton::onRightClick() {
    saveGame();
}

void SaveButton::saveGame() {
    //saving
    std::ofstream saveFile;
    saveFile.open("progress.csv");

    // between values = , new row = /n

    //timer 
    saveFile << game.getTimer()->getGameTime();
    saveFile << "\n"; 

    //array 
    int** boardArray = game.getBoard()->getSaveBoard();
    
    //getting size of array
    int length = game.getBoard()->getSizeY() + 2;
    //std::cout << length << std::endl;
    int width = game.getBoard()->getSizeX() + 2;
    //std::cout << width << std::endl;

    //std::cout << length << " " << width << std::endl;

    saveFile << length << ",";
    saveFile << width << "\n";

    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++)
        {
            saveFile << boardArray[i][j] << ",";
            //std::cout << boardArray[i][j];
        }
        saveFile << "\n";
        //std::cout << std::endl;
    }

    saveFile.close();

}
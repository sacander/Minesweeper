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

    //timer not sure if this works tbh
    saveFile << game.getTimer()->getGameTime();
    saveFile << "\n"; 

    //array 
    int** boardArray = game.getBoard()->getSaveBoard();
    
    //getting size of array
    int length = game.getBoard()->getSizeY();
    int width = game.getBoard()->getSizeX();

    std::cout << length << " " << width << std::endl;

    for (int i = 1; i < length+1; i++){
        for (int j = 1; j < width+1; j++)
        {
            saveFile << boardArray[i][j] << ",";
        }
        saveFile << "\n";
    }

    saveFile.close();

    //needs to be saved:
    //timer, length, width, position of tile 1, revealed t/f, mine t/f, number, flag t/f .........

    //as functions are called, save all to file, then when read call all functions again to restore game state, also set timer 

    //or use boost thing.. but is confusing 
}
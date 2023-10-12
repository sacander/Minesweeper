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
    saveFile.open("progress.txt");

    //timer not sure if this works tbh
    saveFile << game.getTimer()->getGameTime();
    saveFile << ","; 
    saveFile.close();

    //needs to be saved:
    //timer, length, width, position of tile 1, revealed t/f, mine t/f, number, flag t/f .........

    //as functions are called, save all to file, then when read call all functions again to restore game state, also set timer 

    //or use boost thing.. but is confusing 
}
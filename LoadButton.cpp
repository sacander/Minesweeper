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
    std::ifstream saveFile("progress.txt");
    if (saveFile.is_open()){
        while (std::getline(saveFile, dataLine))
            std::cout << dataLine << std::endl;
    }
    saveFile.close();
}
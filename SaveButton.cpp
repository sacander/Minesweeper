#include "SaveButton.h"
#include "Minesweeper.h"
#include <fstream>
#include <iostream>

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
    saveFile << "Test \n";
    saveFile.close();

}
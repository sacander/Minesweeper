#include "SaveButton.h"
#include "Minesweeper.h"

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
}
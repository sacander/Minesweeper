#include "LoadButton.h"
#include "Minesweeper.h"

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
    //saving
}
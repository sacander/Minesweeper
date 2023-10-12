#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include "Entity.h"

using namespace sf;

class SaveButton: public Entity {
    public:
    SaveButton(Vector2f pos, Minesweeper &game);
    ~SaveButton();
    void onLeftClick();
    void onRightClick();
    void saveGame();
};

#endif
#ifndef LOADBUTTON_H
#define LOADBUTTON_H

#include "Entity.h"

using namespace sf;

class LoadButton: public Entity {
    public:
    LoadButton(Vector2f pos, Minesweeper &game);
    ~LoadButton();
    void onLeftClick();
    void onRightClick();
    void loadGame();
};
#endif
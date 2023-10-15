#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include "Entity.h"

using namespace sf;

class SaveButton : public Entity {
    public:
        SaveButton(Vector2f pos, Minesweeper &game);
        ~SaveButton();
        void onLeftClick();  // called on left click, calls saveGame()
        void onRightClick(); // called on right click, calls saveGame()
        void saveGame();     // saves the current game progress to a file
};

#endif
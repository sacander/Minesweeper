#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include "Entity.h"

class NewGameButton: Entity {
    private:
    sf::Text text; 
    public:
    void onLeftClick();
    void onRightClick();
    void newGame();
};

#endif
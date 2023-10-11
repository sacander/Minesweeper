#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include "Entity.h"

using namespace sf;

class NewGameButton: public Entity {
    private:
    sf::Text text; 
    public:
    NewGameButton(Vector2f pos, Minesweeper &game);
    ~NewGameButton();
    void onLeftClick();
    void onRightClick();
    void newGame();
};

#endif
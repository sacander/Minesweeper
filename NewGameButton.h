#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include "Entity.h"

using namespace sf;

class NewGameButton : public Entity {
 public:
  NewGameButton(Vector2f pos, Minesweeper &game);
  ~NewGameButton();
  void onLeftClick();   // called on left click, calls newGame()
  void onRightClick();  // called on right click, calls newGame()
  void newGame();  // gets custom board size and mines for the new board from
                   // the user
};

#endif
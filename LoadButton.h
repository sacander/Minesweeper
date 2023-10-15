#ifndef LOADBUTTON_H
#define LOADBUTTON_H

#include "Entity.h"

using namespace sf;

class LoadButton : public Entity {
 public:
  LoadButton(Vector2f pos, Minesweeper &game);
  ~LoadButton();
  void onLeftClick(); // called on a left click, calls loadGame()
  void onRightClick(); // called on a right click, calls loadGame()
  void loadGame();  // called when button click, reads in info from save file
};
#endif
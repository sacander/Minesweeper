#include "Minesweeper.h"
#include <iostream>

int main() {
    std::cout << "Minesweeper is a game where you need to "
    "reveal all the safe tiles, while avoiding revealing "
    "mines. You can reveal tiles by left clicking on them. "
    "You can flag tiles which you believe are mines by right "
    "clicking, and undo this by right clicking again. You "
    "can determine positions of mines by the revealed tiles, "
    "which display a number representing the number of the "
    "surrounding tiles which contain mines. There are also "
    "options to create a new game, save your game, and load "
    "a saved game which can be accessed by clicking on the "
    "respective buttons." << std::endl;
    Minesweeper minesweeper(500, "Minesweeper");
    minesweeper.run();

    return 0;
}
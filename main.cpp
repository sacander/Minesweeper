#include "Minesweeper.h"

int main() {
    Minesweeper minesweeper(500, "Minesweeper");
    minesweeper.newBoard(8,8,8);
    minesweeper.run();

    return 0;
}
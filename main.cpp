#include "Minesweeper.h"

int main() {
    Minesweeper minesweeper(500, "Minesweeper");
    minesweeper.newBoard(5,5,3);
    minesweeper.run();

    return 0;
}
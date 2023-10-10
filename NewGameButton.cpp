#include "NewGameButton.h"
#include <iostream>

void NewGameButton::onLeftClick() {
    newGame();
}

void NewGameButton::onLeftClick() {
    newGame();
}

void NewGameButton::newGame() {
    //initialising length width and number of mines 
    int length = 0;
    int width = 0;
    int numberMines = 0;

    //getting input and confirming is acceptable 
    std::cout << "Please enter the desired length of the board (anywhere between 8 to 50 tiles): " << std::endl;
    std::cin >> length;

    while (length > 50 | length < 8) {
        std::cout << "Please enter a length greater than 8 and less than 50: " << std::endl;
    std::cin >> length;
    };

    std::cout << "Please enter the desired width of the board (anywhere between 8 to 50 tiles): " << std::endl;
    std::cin >> width;

    while (width > 50 | width < 8) {
        std::cout << "Please enter a width greater than 8 and less than 50: " << std::endl;
    std::cin >> width;
    };
    
    std::cout << "Please enter the desired number of mines (from 1 up to " << length * width - 1 << " tiles): " << std::endl;
    std::cin >> numberMines;

    while (numberMines > (width * length) - 1 | numberMines < 1) {
        std::cout << "Please enter a number of mines from 1 up to " << length * width - 1 << " tiles:" << std::endl;
    std::cin >> numberMines;
    };

    //once new board created, this can be called:
    //newBoard(length, width, numberMines);
}
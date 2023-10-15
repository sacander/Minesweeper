#include "NewGameButton.h"
#include "Minesweeper.h"
#include <iostream>
#include <limits>

//sets the texture for the new game button
NewGameButton::NewGameButton(Vector2f pos, Minesweeper &game) 
: Entity("./textures/newgame.png", pos, game) {
}

//on left click the new game function is called
void NewGameButton::onLeftClick() {
    newGame();
}

//on right click the new game function is called
void NewGameButton::onRightClick() {
    newGame();
}

//when called, the user is prompted for a length, width and number of mines for their game, and these values are given to the newboard function
void NewGameButton::newGame() {
    //initialising length width and number of mines 
    int length = 0;
    int width = 0;
    int numberMines = 0;

    //getting input for length
    std::cout << "Please enter the desired length of the board (anywhere between 8 to 30 tiles): " << std::endl;
    std::cin >> length;
    
    //confirming acceptable input
    while (length > 30 | length < 8 | std::cin.fail() | std::cin.peek() == '.') {
        //clear 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //reprompts user
        std::cout << "Please enter an integer (whole number) length greater than 8 and less than 30: " << std::endl;
        std::cin >> length;
    };

    //getting input for width
    std::cout << "Please enter the desired width of the board (anywhere between 8 to 30 tiles): " << std::endl;
    std::cin >> width;

    //confirming acceptable input
    while (width > 30 | width < 8 | std::cin.fail() | std::cin.peek() == '.') {
        //clear 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //reprompts user
        std::cout << "Please enter an integer (whole number) width greater than 8 and less than 30: " << std::endl;
        std::cin >> width;
    };
    
    //getting input for mines, minimum of 1 mine up to the total number of tiles - 2 
    //(this maximum sets all tiles to mines except 2, as first tile clicked does not contain mine, so after game commences only one other tile would not contain a mine)
    std::cout << "Please enter the desired number of mines (from 1 up to " << length * width - 2 << " mines, recommended between " << length * width * 0.1 << " and " << length * width * 0.2 << "): " << std::endl;
    std::cin >> numberMines;

    //confirming acceptable input 
    while (numberMines > (width * length) - 2 | numberMines < 1 | std::cin.fail() | std::cin.peek() == '.') {
        //clear 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //reprompts user
        std::cout << "Please enter an integer (whole number) number of mines from 1 up to " << length * width - 2 << " tiles: " << std::endl;
        std::cin >> numberMines;
    };

    game.newBoard(length, width, numberMines); 

    //for testing 
    std::cout << length << " " << width << " " << numberMines << std::endl;
}

NewGameButton::~NewGameButton() {
    //deconstructor
}
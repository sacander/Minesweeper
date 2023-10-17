#include "NewGameButton.h"

#include <cmath>
#include <iostream>
#include <limits>

#include "Minesweeper.h"

// sets the texture for the new game button
NewGameButton::NewGameButton(Vector2f pos, Minesweeper &game)
    : Entity("./textures/newgame.png", pos, game) {}

// on left click the new game function is called
void NewGameButton::onLeftClick() { newGame(); }

// on right click the new game function is called
void NewGameButton::onRightClick() { newGame(); }

// when called, the user is prompted for a length, width and number of mines for
// their game, and these values are given to the newboard function
void NewGameButton::newGame() {
  // initialising length width and number of mines
  int length = 0;
  int width = 0;
  int numberMines = 0;

  // getting input for length (acceptable range determined by what fits in game
  // window)
  std::cout << "Please enter the desired length of the board (anywhere between "
               "5 to 26 tiles): "
            << std::endl;
  std::cin >> length;

  // confirming acceptable input
  while (length > 26 || length < 5 || std::cin.fail() ||
         std::cin.peek() == '.') {
    // clear
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // reprompts user
    std::cout << "Please enter an integer (whole number) length greater than 5 "
                 "and less than 26: "
              << std::endl;
    std::cin >> length;
  };

  // getting input for width (acceptable range determined by what fits in game
  // window)
  std::cout << "Please enter the desired width of the board (anywhere between "
               "5 to 26 tiles): "
            << std::endl;
  std::cin >> width;

  // confirming acceptable input
  while (width > 26 || width < 5 || std::cin.fail() || std::cin.peek() == '.') {
    // clear
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // reprompts user
    std::cout << "Please enter an integer (whole number) width greater than 5 "
                 "and less than 26: "
              << std::endl;
    std::cin >> width;
  };

  // getting input for mines, must be between 10% and 30% as this is the
  // standard ratio of mine tiles to non-mine tiles
  std::cout << "Please enter the desired number of mines (from "
            << floor(length * width * 0.1) << " to "
            << floor(length * width * 0.3) << "): " << std::endl;
  std::cin >> numberMines;

  // confirming acceptable input
  while (numberMines > floor(length * width * 0.3) ||
         numberMines < floor(length * width * 0.1) || std::cin.fail() ||
         std::cin.peek() == '.') {
    // clear
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // reprompts user
    std::cout << "Please enter an integer (whole number) number of mines from "
              << floor(length * width * 0.1) << " to "
              << floor(length * width * 0.3) << " tiles: " << std::endl;
    std::cin >> numberMines;
  };

  //resets and stops the timer
  game.getTimer()->resetTimer();
  game.getTimer()->stopTimer();

  //call newBoard()
  game.newBoard(length, width, numberMines);

  // for testing
  std::cout << length << " " << width << " " << numberMines << std::endl;
}

NewGameButton::~NewGameButton() {
  // deconstructor
}
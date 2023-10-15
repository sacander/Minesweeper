// Tests behaviour of the load button class
#include <fstream>
#include <iostream>

#include "LoadButton.h"
#include "Minesweeper.h"

class LoadButtonEdit : public LoadButton {
 public:
  // added variables to store info read from file in load game function for
  // testing
  int** array;
  int rows;
  int columns;
  int time;
  // reimplemented function to be able to save values for testing
  void loadGame(std::string file) {
    // load from a file
    std::string dataLine;
    std::ifstream saveFile(file);

    // initialise values
    int elapsedTime = 0;
    int length = 0;
    int width = 0;

    if (saveFile.is_open()) {
      // get timer info
      std::getline(saveFile, dataLine, '\n');
      elapsedTime = stoi(dataLine);
      // std::cout << elapsedTime << std::endl;

      // get length and width
      std::getline(saveFile, dataLine, ',');
      length = stoi(dataLine);

      std::getline(saveFile, dataLine, '\n');
      width = stoi(dataLine);

      // create the array using length and width
      int** boardArray = new int*[length];
      for (int i = 0; i < length; i++) {
        boardArray[i] = new int[width]{};
      }

      // read info into array
      for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
          std::getline(saveFile, dataLine, ',');
          boardArray[i][j] = stoi(dataLine);
        }
      }

      // for (int i = 0; i < length; i++){
      //     for (int j = 0; j < width; j++) {
      //         std::cout << boardArray[i][j] << " ";
      //     }
      // std::cout << std::endl;
      // }

      // set game time to previous save's timer
      // ORIGINAL LINES
      // game.getTimer()->startTimer();
      // game.getTimer()->setInitialTime(time(0)-elapsedTime);
      // NEW LINE 
      time = elapsedTime;

      // call load board function
      // ORIGINAL LINE
      // game.getBoard()->loadBoard(boardArray, width, length, &game);
      // NEW LINE
      rows = length;
      columns = width;
      array = boardArray;
    }
    saveFile.close();
  }
  LoadButtonEdit(Vector2f pos, Minesweeper& game) : LoadButton(pos, game) {}
};

class LoadButtonTest {
 public:
  void tests() {
    //test 1 for minimum size array
    std::cout << "Test 1: 7 x 7 array (as saved and loaded board have extra 2 "
                 "tiles of padding)"
              << std::endl;
    int** board1 = new int*[7];
    for (int i = 0; i < 7; i++) {
      board1[i] = new int[7];
    }
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7; j++) {
        board1[i][j] = j + 1;
      }
    }
    loadGameTest("test1.csv", board1, 7, 7, 30);

    //test 2 for maximum size array
    std::cout << "Test 2: 28 x 28 array (as saved and loaded board have extra "
                 "2 tiles of padding)"
              << std::endl;
    int** board2 = new int*[28];
    for (int i = 0; i < 28; i++) {
      board2[i] = new int[28];
    }
    for (int i = 0; i < 28; i++) {
      for (int j = 0; j < 28; j++) {
        board2[i][j] = j + 1;
        // std::cout << board2[i][j];
      }
      // std::cout << " " << std::endl;
    }
    loadGameTest("test2.csv", board2, 28, 28, 312);
  }

 private:
  void loadGameTest(std::string csv, int** _array, int _rows, int _columns,
                    int _time) {
    Minesweeper game(100, "SaveButton Test");
    LoadButtonEdit test(sf::Vector2f(0, 0), game);
    test.loadGame(csv);

    bool arraySame = true;

    std::ifstream saveFile(csv);

    //check if array read in by loadGame() matches the array given
    for (int i = 0; i < test.rows; i++) {
      for (int j = 0; j < test.columns; j++) {
        if (_array[i][j] != test.array[i][j]) {
          arraySame = false;
        }
      }
    }

    if (arraySame) {
      std::cout << "Array loaded successfully" << std::endl;
    } else {
      std::cout << "FAIL Array not loaded successfully" << std::endl;
    }

    //check if the number of rows read in by loadGame() matches the number of rows given
    if (_rows == test.rows) {
      std::cout << "Length loaded successfully" << std::endl;
    } else {
      std::cout << "FAIL length not loaded successfully" << std::endl;
    }

    //check if the number of rows read in by loadGame() matches the number of rows given
    if (_columns == test.columns) {
      std::cout << "Width loaded successfully" << std::endl;
    } else {
      std::cout << "FAIL width not loaded successfully" << std::endl;
    }

    //check if the time read in by loadGame() matches the time given
    if (_time == test.time) {
      std::cout << "Time loaded successfully" << std::endl;
    } else {
      std::cout << "FAIL time not loaded successfully" << std::endl;
    }
  }
};

int main() {
  LoadButtonTest loadButtonTest;
  loadButtonTest.tests();
}
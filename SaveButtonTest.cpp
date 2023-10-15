// Tests behaviour of the save button class 
#include "SaveButton.h"
#include "Minesweeper.h"
#include <fstream>
#include <iostream>

class SaveButtonInput : public SaveButton {
    public: 
    //reimplementing saveGame function to instead use an array input and values for testing
    void saveGame(int** board, int sizeY, int sizeX, int time) {
        //saving
        std::ofstream saveFile;
        saveFile.open("progress.csv");

        // between values = , new row = /n

        //timer
        //ORIGINAL LINE
        //saveFile << game.getTimer()->getGameTime();
        //NEW LINE
        saveFile << time;
        saveFile << "\n"; 

        //array 

        //ORIGINAL LINE
        //int** boardArray = game.getBoard()->getSaveBoard();

        //REPLACEMENT FOR TESTING
        int** boardArray = board;

        //getting size of array
        //ORIGINAL LINE
        //int length = game.getBoard()->getSizeY() + 2;
        //REPLACEMENT FOR TESTING
        int length = sizeY;
        //std::cout << length << std::endl;

        //ORIGINAL LINE
        //int width = game.getBoard()->getSizeX() + 2;
        //REPLACEMENT FOR TESTING
        int width = sizeX;

        //std::cout << width << std::endl;

        //std::cout << length << " " << width << std::endl;

        saveFile << length << ",";
        saveFile << width << "\n";

        for (int i = 0; i < length; i++){
            for (int j = 0; j < width; j++)
            {
                saveFile << boardArray[i][j] << ",";
                //std::cout << boardArray[i][j];
            }
            saveFile << "\n";
            //std::cout << std::endl;
        }

        saveFile.close();
    }
    //reimplementing function with exact same code, except saveGame() is not called so test can run)
    void onLeftClick() {
        //if timer has begun, allow save
        if (game.getBoard()->getRevealedTiles() != 0) {
           std::cout << "saving..." << std::endl;
           //saveGame();
        } else {
            std::cout << "Cannot save a game that has not commenced" << std::endl;
        }
    }
    //same for the right click function
    void onRightClick() {
        //if timer has begun, allow save
        if (game.getBoard()->getRevealedTiles() != 0) {
           std::cout << "saving..." << std::endl;
           //saveGame();
        } else {
            std::cout << "Cannot save a game that has not commenced" << std::endl;
        }
    }
    //constructor for test class 
    SaveButtonInput(Vector2f pos, Minesweeper &game) : SaveButton(pos, game) {}
};  

class SaveButtonTest {
    public:
    void tests() {
        //testing if saving works:
        {
        //testing array of zeroes
        int **board1 = new int*[6]{0};
        for (int i = 0; i < 6; i++) {
            board1[i] = new int[7]{0};
        }
        std::cout << "Test 1: Array of zeroes" << std::endl;
        testSaving(board1, 6, 7, 10);

        //array with non-zero values
        int **board2 = new int*[15];
        for (int i = 0; i < 15; i++) {
            board2[i] = new int[10];
        }
        int value = 1;
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 10; j++) {
                board2[i][j] = value;
                value++;
            }
        }
        std::cout << "\nTest 2: Array of non-zeroes" << std::endl;
        testSaving(board2, 15, 10, 300);

        //smallest possible array 5x5 (with random values)
        int **board3 = new int*[5];
        for (int i = 0; i < 5; i++) {
            board3[i] = new int[5];
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                board3[i][j] = value;
                value = 1+rand()%100;
            }
        }
        std::cout << "\nTest 3: 5x5 (smallest possible array) of random numbers" << std::endl;
        testSaving(board3, 5, 5, 62);

        //largest possible array 26x26
        int **board4 = new int*[26];
        for (int i = 0; i < 26; i++) {
            board4[i] = new int[26];
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                board4[i][j] = value;
                value = 1+rand()%100;
            }
        }
        std::cout << "\nTest 4: 26x26 (largest possible array) of random numbers" << std::endl;
        testSaving(board4, 26, 26, 452);
        }
        //testing if saving is allowed / not allowed correctly
        testAllowSave();
    }
    private:
        void testSaving(int ** board, int length, int width, int time) {
            Minesweeper game (100, "SaveButton Test");
            SaveButtonInput test1(sf::Vector2f(0,0), game);

            test1.saveGame(board, length, width, time);



            //reading in data from save file
            std::string dataLine;
            std::ifstream saveFile("progress.csv");

            if (saveFile.is_open()){
                std::getline(saveFile, dataLine, '\n');
                if (time == stoi(dataLine)) {
                    std::cout << "Time saved successfully" << std::endl;
                } else {
                    std::cout << "FAIL, time not saved successfully" << std::endl;
                }

                std::getline(saveFile, dataLine, ',');
                if (length == stoi(dataLine)) {
                    std::cout << "Length saved successfully" << std::endl;
                } else {
                    std::cout << "FAIL, length not saved successfully" << std::endl;
                }

                std::getline(saveFile, dataLine, '\n');
                if (width == stoi(dataLine)) {
                    std::cout << "Width saved successfully" << std::endl;
                } else {
                    std::cout << "FAIL, width not saved successfully" << std::endl;
                }  

                //see if array matches 
                bool arrayPass = true;
                for (int i = 0; i < length; i++) {
                    for (int j = 0; j < width; j++) {
                        std::getline(saveFile, dataLine, ',');
                        if (board[i][j] != stoi(dataLine)) {
                            arrayPass = false;
                        }
                    }
                }

                if (arrayPass) {
                    std::cout << "Array saved successfully" << std::endl;
                } else {
                    std::cout << "FAIL, array not saved successfully" << std::endl;
                }

            }


        }
        void testAllowSave() {
            Minesweeper game (100, "SaveButton Test");

            //game not started
            SaveButtonInput test1(sf::Vector2f(0,0), game);
            std::cout << "\nGame not started, should not allow save:" << std::endl;
            test1.onLeftClick();
            test1.onRightClick();

            game.getBoard()->incrementRevealedTiles(0,0);
            std::cout << "Game started, should allow save:" << std::endl;
            test1.onLeftClick();
            test1.onRightClick();
        }
};

int main() {
    SaveButtonTest saveButtonTest;
    saveButtonTest.tests();
}

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
    //constructor for test class 
    SaveButtonInput(Vector2f pos, Minesweeper &game) : SaveButton(pos, game) {}
};  

class SaveButtonTest {
    public:
    void tests() {
        //testing array of zeroes
        int **board1 = new int*[5]{0};
        for (int i = 0; i < 5; i++) {
            board1[i] = new int[5]{0};
        }
        testSaving(board1, 5, 6, 10);
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
                if (time = stoi(dataLine)) {
                    std::cout << "Time saved successfully" << std::endl;
                } else {
                    std::cout << "FAIL, time not saved successfully" << std::endl;
                }

                std::getline(saveFile, dataLine, ',');
                if (length = stoi(dataLine)) {
                    std::cout << "Length saved successfully" << std::endl;
                } else {
                    std::cout << "FAIL, length not saved successfully" << std::endl;
                }

                std::getline(saveFile, dataLine, '\n');
                if (width = stoi(dataLine)) {
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
};

int main() {
    SaveButtonTest saveButtonTest;
    saveButtonTest.tests();
}

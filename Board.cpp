#include "Board.h"
#include "Minesweeper.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>
#include <cmath>

Board::Board(int width, int height, int mines, Minesweeper* game, int clickX, int clickY){

    xSize = width;
    ySize = height;
    totalMines = mines;

    if (clickX < 0 || clickY < 0){
        tiles = new Tile**[height + 2];
        for (int i = 0; i < height + 2; i++){
            tiles[i] = new Tile*[width + 2];
            for (int j = 0; j < width + 2; j++){   
                tiles[i][j] = new Mine(Vector2f(boardX + 16*j, boardY + 16*i), *game, j, i);
            }
        }
    }
}

// generateBoard(xSize, ySize, totalMines, game, x, y
void Board::generateBoard(Minesweeper * game, int clickY, int clickX, int ** board){

    //Only calculate new board if a board is not passed
    if(!board){  
        //After first click re-calculate the board
        std::vector<int*> mineCoords;

        for (int i = 0; i < xSize; i++){
            for (int j = 0; j < ySize; j++)
            {
                //width, height [][]
                int* coord = new int[2];
                coord[0] = j;
                coord[1] = i;
                mineCoords.push_back(coord);
            }
        }

        std::cout << "finished vector" << std::endl;

        //First n pointers are mine coordinates
        //std::shuffle(mineCoords.begin(), mineCoords.end(), std::default_random_engine(time(0)));
        std::default_random_engine randNum(time(0));

        int N = mineCoords.size();
        for(int j=N-1; j>N - totalMines - 2; --j) {
            int r = randNum() % (j+1);
            std::swap(mineCoords[j], mineCoords[r]);
        }
        
        std::cout << "shuffle vector" << std::endl;

        //create board 2d array of 0's (with padding)
        board = new int*[ySize + 2];
        for (int i = 0; i < ySize + 2; i++){
            board[i] = new int[xSize + 2]{};
        }

        //Assign 9 to where mines go 
        std::cout << "assign mines" << std::endl;
        N = mineCoords.size();
        int m = 0;
        while (m < totalMines){
            int y = mineCoords.at(N-1)[0] + 1;
            int x = mineCoords.at(N-1)[1] + 1;
            
            if((y == clickY) && (x = clickX)){
                N--;
                continue;
            } else {
                //delete[] mineCoords[i];
                board[y][x] = 9;
                //add 1 to adjacent tiles (tiles with 9 or more are mines)
                for (int j = 0; j < 3; j++){
                    board[y + 1 - j][x+1] += 1;
                    board[y + 1 - j][x-1] += 1;
                }
                board[y + 1][x] += 1;
                board[y - 1][x] += 1;
                m++;
            }
            N--;
        }
        std::cout << "begin print mines" << std::endl;
        //Remember this template for next time
        saveBoard = board;

        //Clean tiles for new allocation
        cleanTiles(ySize + 2, xSize + 2);
    }

    int test = 0;
    
    std::cout << "y size " << ySize << std::endl;
    std::cout << "x size " << xSize << std::endl;

    //Recreate tile array
    tiles = new Tile**[ySize + 2];
    for (int i = 0; i < ySize + 2; i++){
        tiles[i] = new Tile*[xSize + 2];
        for (int j = 0; j < xSize + 2; j++){   
            if (i != 0 && i != ySize + 1 && j != 0 && j != xSize + 1){
                if (abs(board[i][j]) >= 9 && abs(board[i][j]) < 100){
                    std::cout << "mine " << test;
                    tiles[i][j] = new Mine(sf::Vector2f(boardX + 16*j, boardY + 16*i), *game, j, i);
                } else {
                    int value = board[i][j];
                    if (abs(value) < 100){
                        tiles[i][j] = new Number(Vector2f(boardX + 16*j, boardY + 16*i), *game, j, i, abs(value));
                    } else {
                        value = abs(value) - 100;
                        tiles[i][j] = new Number(Vector2f(boardX + 16*j, boardY + 16*i), *game, j, i, value);
                        tiles[i][j]->showTile(); 
                    }
                    
                    std::cout << "Num " << test;
                }
                //Toggle flags
                if(board[i][j] < 0){
                    tiles[i][j]->toggleFlag();
                }
            } else {
                tiles[i][j] = nullptr;
                std::cout << "null " << test;
                test++;
            }
            //std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "made board" << std::endl; 

    //Reveal first tile clicked if not loading new board
    if(!loading) tiles[clickX][clickY]->showTile();  
    std::cout << "opened tile" << std::endl;
}

//Load a board from a save
void Board::loadBoard(int ** board, int width, int height, Minesweeper * game){

    //Clean tiles for new board
    cleanTiles(ySize + 2, xSize + 2);
    for (int i = 0; i < ySize + 2; i++){
        delete[] saveBoard[i];
    }
    delete[] saveBoard;
    //Offset from original board creation
    xSize = width-2;
    ySize = height-2;
    loading = true;
    saveBoard = board;
    generateBoard(game,-1,-1,board);
    loading = false;
    game->setGameActive(true);
}

//Draw board
void Board::draw(RenderWindow *window){
    for (int i = 0; i < ySize; i++){
        for (int j = 0; j < xSize; j++){
            tiles[i+1][j+1]->draw(window);
        }  
    }
}

//Click on tile event
void Board::onClickEvent(RenderWindow *window, Event event){
    for (int i = 0; i < ySize; i++){
        for (int j = 0; j < xSize; j++){
            tiles[i+1][j+1]->onClickEvent(window, event);
        }  
    }
}

//Checks if all tiles have been revealed or not
bool Board::incrementRevealedTiles(int x, int y) {
    revealedTiles++;
    

    //If all (non-mine) tiles have been revealed
    if (revealedTiles == xSize * ySize - totalMines){
        return true;
    }
    return false;
}

//Reveals all mines when game is lost
void Board::revealMines(Tile* tile){
    std::cout << "Reveal Mines:" << std::endl;

    for (int i = 0; i < xSize; i++){
        for (int j = 0; j < ySize; j++){
            //Check if tile is a mine or not (based on a known mine location)
            //std::cout << "CHeck" << std::endl;
            if (typeid(*tile) == typeid(*tiles[j+1][i+1])){
                //std::cout << "Reveal" << std::endl;
                tiles[j+1][i+1]->showTile();
        }
    }
    }
}

//Swaps tiles if the first tile clicked is a mine
// void Board::swapTiles(int x, int y, Minesweeper * game) {
//     //Tile* temp = tiles[x][y];
//     //tiles[x][y] = tiles[firstSafeX][firstSafeY];
//     //tiles[firstSafeX][firstSafeY] = temp;
//     //swappedTiles = true;
//     generateBoard(xSize, ySize, totalMines, game, x, y);
    
// }

//Returns an array of addresses to tiles that are adjacent
std::vector<Tile *> Board::getAdjacentTiles(int x, int y) {
    std::vector<Tile*> adjTiles;
    std::cout << "Adj Tiles" << std::endl;
    //Only return adjacent if not loading a new game
    if(!loading){
        for (int j = 0; j < 3; j++){
        if(tiles[y + 1 - j][x+1]) adjTiles.push_back(tiles[y + 1 - j][x+1]);
        if(tiles[y + 1 - j][x-1]) adjTiles.push_back(tiles[y + 1 - j][x-1]);
        }
        if(tiles[y + 1][x]) adjTiles.push_back(tiles[y + 1][x]);
        if(tiles[y - 1][x]) adjTiles.push_back(tiles[y - 1][x]);

    }
    return adjTiles;
}

int Board::getRevealedTiles() {
    return revealedTiles;
}

int** Board::getSaveBoard(){
    return saveBoard;
}

int Board::getSizeX() {
    return xSize;
}

int Board::getSizeY() {
    return ySize; 
}

void Board::cleanTiles(int height, int width){
    std::cout << "clean memory " << std::endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            delete tiles[i][j];
        }
        delete[] tiles[i];
    }
    delete[] tiles;
    std::cout << "done cleaning memory " << std::endl;
}

//Memory cleanup
Board::~Board(){
    std::cout << "Board deconstructor" << std::endl;
    cleanTiles(ySize + 2, xSize + 2);
    for (int i = 0; i < ySize + 2; i++){
        delete[] saveBoard[i];
    }
    delete[] saveBoard;
}


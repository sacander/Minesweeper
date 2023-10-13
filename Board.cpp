#include "Board.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>

Board::Board(int width, int height, int mines, Minesweeper* game){

    xSize = width;
    ySize = height;
    totalMines = mines;

    std::vector<int*> mineCoords;

    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++)
        {
            //width, height [][]
            int* coord = new int[2];
            coord[0] = j;
            coord[1] = i;
            mineCoords.push_back(coord);
        }
    }

    //First n pointers are mine coordinates
    std::shuffle(mineCoords.begin(), mineCoords.end(), std::default_random_engine(time(0))); 

    //create board 2d array of 0's (with padding)
    int** board = new int*[height + 2];
    for (int i = 0; i < height + 2; i++){
        board[i] = new int[width + 2]{};
    }

    //Assign 9 to where mines go and 
    for (int i = 0; i < mines; i++){
        int y = mineCoords.at(i)[0] + 1;
        int x = mineCoords.at(i)[1] + 1;
        board[y][x] = 9;
        //add 1 to adjacent tiles (tiles with 9 or more are mines)
        for (int j = 0; j < 3; j++){
            board[y + 1 - j][x+1] += 1;
            board[y + 1 - j][x-1] += 1;
        }
        board[y + 1][x] += 1;
        board[y - 1][x] += 1;
    }
    
    //Remember this template for next time
    saveBoard = board;

    //Assign a safe tile coordinate
    firstSafeY = mineCoords.at(mines)[0] + 1;
    firstSafeX = mineCoords.at(mines)[1] + 1;

for (int i = 1; i < height+1; i++){
        for (int j = 1; j < width+1; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
}

    //Create tile array
    tiles = new Tile**[height + 2];
    for (int i = 0; i < height + 2; i++){
        tiles[i] = new Tile*[width + 2];
        for (int j = 0; j < width + 2; j++){   
            if (i != 0 && i != height + 1 && j != 0 && j != width + 1){
                if (board[j][i] >= 9){
                    tiles[i][j] = new Mine(sf::Vector2f(boardX + 16*i, boardY + 16*j), *game, j, i);
                } else {
                    int value = board[j][i];
                    tiles[i][j] = new Number(Vector2f(boardX + 16*i, boardY + 16*j), *game, j, i, value);
                }
            } else {
                std::cout << "nullptr" << std::endl;
                tiles[i][j] = nullptr;
            }
            //std::cout << board[i][j] << " ";
        }
        //std::cout << std::endl;
    }

}

void Board::draw(RenderWindow *window){
    for (int i = 0; i < ySize; i++){
        for (int j = 0; j < xSize; j++){
            tiles[i+1][j+1]->draw(window);
        }  
    }
}

void Board::onClickEvent(RenderWindow *window, Event event){
    for (int i = 0; i < ySize; i++){
        for (int j = 0; j < xSize; j++){
            tiles[i+1][j+1]->onClickEvent(window, event);
        }  
    }
}

//Checks if all tiles have been revealed or not
bool Board::incrementRevealedTiles() {
    revealedTiles++;

    //If all tiles have been revealed
    if (revealedTiles == xSize * ySize){
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

void Board::swapTiles(int x, int y) {
    Tile* temp = tiles[x][y];
    tiles[x][y] = tiles[firstSafeX][firstSafeY];
    tiles[firstSafeX][firstSafeY] = temp;
    swappedTiles = true;
}

//Returns an array of addresses to tiles that are adjacent
std::vector<Tile *> Board::getAdjacentTiles(int x, int y) {

    std::vector<Tile*> adjTiles;
    std::cout << "Adj Tiles" << std::endl;
    //TODO : combine if statements

    for (int j = 0; j < 3; j++){
        if(tiles[y + 1 - j][x+1]) adjTiles.push_back(tiles[y + 1 - j][x+1]);
        if(tiles[y + 1 - j][x-1]) adjTiles.push_back(tiles[y + 1 - j][x-1]);
    }
        if(tiles[y + 1][x]) adjTiles.push_back(tiles[y + 1][x]);
        if(tiles[y - 1][x]) adjTiles.push_back(tiles[y - 1][x]);

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

//Memory cleanup
Board::~Board(){
    delete[] tiles;
}
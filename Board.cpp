#include "Board.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>

Board::Board(int width, int height, int mines){
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

    for (int i = 0; i < 10; i++)
    {
        std::cout << mineCoords.at(i)[0] << ' ' << mineCoords.at(i)[1] << std::endl;
    }
    std::cout << "End vector" << std::endl;

    //First n pointers are mine coordinates
    std::shuffle(mineCoords.begin(), mineCoords.end(), std::default_random_engine(time(0))); 

    //create board 2d array of 0's
    int** board = new int*[height];
    for (int i = 0; i < height; i++){
        board[i] = new int[width]{};
    }

    //Assign -1 to where mines go
    for (int i = 0; i < mines; i++){
        int y = mineCoords.at(i)[0];
        int x = mineCoords.at(i)[1];
        board[y][x] = -1;
    }
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
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

    //Reveal mines
    for (int i = 0; i < xSize; i++){
        for (int j = 0; j < ySize; j++){
            //Check if tile is a mine or not (based on a known mine location)
            if (typeid(*tile) != typeid(*tiles[i][j])){
                tiles[i][j]->showTile();
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

    //TODO : combine if statements

    //top left tile
    if (x > 0 && y > 0) adjTiles.push_back(tiles[y-1][x - 1]);
    //top right tile
    if (x < xSize - 1 && y > 0) adjTiles.push_back(tiles[y+1][x - 1]);
    //Bottom left tile
    if (x > 0 && y < ySize - 1) adjTiles.push_back(tiles[y-1][x + 1]);
    //bottom right tile
    if (x < xSize - 1 && y < ySize - 1) adjTiles.push_back(tiles[y+1][x + 1]);
    //Left tle
    if (x > 0) adjTiles.push_back(tiles[y][x - 1]);
    //right tile
    if (x < xSize - 1) adjTiles.push_back(tiles[y][x + 1]);
    //top tile
    if (y > 0) adjTiles.push_back(tiles[y-1][x]);
    //bottom tile
    if (y < ySize - 1) adjTiles.push_back(tiles[y+1][x]);

    return adjTiles;
}

int Board::getRevealedTiles() {
    return revealedTiles;
}

//Memory cleanup
Board::~Board(){
    delete[] tiles;
}
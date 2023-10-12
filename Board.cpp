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
    
for (int i = 1; i < height+1; i++){
        for (int j = 1; j < width+1; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
}

    //Create tile array (remove buffer edges)
    tiles = new Tile**[height];
    for (int i = 1; i < height + 1; i++){
        tiles[i-1] = new Tile*[width];
        for (int j = 1; j < width + 1; j++)
        {
            if (board[j][i] >= 9){
                tiles[i-1][j-1] = new Mine(sf::Vector2f(50 + 16*i, 50 + 16*j), *game, j-1, i-1);
            } else {
                int value = board[j][i];
                tiles[i-1][j-1] = new Number(Vector2f(50 + 16*i, 50 + 16*j), *game, j-1, i-1, value);
            }
            //std::cout << board[i][j] << " ";
        }
        //std::cout << std::endl;
    }

}

void Board::draw(RenderWindow *window){
    for (int i = 0; i < ySize; i++){
        for (int j = 0; j < xSize; j++){
            tiles[i][j]->draw(window);
        }  
    }
}

void Board::onClickEvent(RenderWindow *window, Event event){
    for (int i = 0; i < ySize; i++){
        for (int j = 0; j < xSize; j++){
            tiles[i][j]->onClickEvent(window, event);
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
            if (typeid(*tile) == typeid(*tiles[j][i])){
                //std::cout << "Reveal" << std::endl;
                tiles[j][i]->showTile();
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
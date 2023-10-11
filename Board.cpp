#include "Board.h"
#include <vector>
#include <typeinfo>

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
void Board::revealMines(){

    Mine* temp = new Mine;

    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            //if type of tile is a mine reveal it
            if (typeid(*temp) == typeid(*tiles[i][j]))
            {
                tiles[i][j]->showTile();
            }
            
        }
    }
}

void Board::swapTiles(int x, int y) {
    Tile* temp = tiles[x][y];
    tiles[x][y] = tiles[firstSafeX][firstSafeY];
    tiles[firstSafeX][firstSafeY] = temp;
}

//Returns an array of addresses to tiles that are adjacent
std::vector<Tile **> Board::getAdjacentTiles(int x, int y) {

    std::vector<Tile**> adjTiles;

    //Assuming 0,0 is the bottom left of the grid (can be changed)
    //Positive coord is right and upwards
    //Add adj tiles to the left (if not on a border)
    if (x > 0){
       for (int i = 0; i < 3; i++){
            adjTiles.push_back(tiles[x-1][y - 1 + i]);
       }
    }

    if (x < xSize - 1){
       for (int i = 0; i < 3; i++){
            adjTiles.push_back(tiles[x+1][y - 1 + i]);
       }
    }
    
    if (y > 0){
        adjTiles.push_back(tiles[x][y - 1]);
    }

    if (y < ySize - 1){
        adjTiles.push_back(tiles[x][y + 1]);
    }

    return adjTiles
}

int Board::getRevealedTiles() {
    return revealedTiles;
}

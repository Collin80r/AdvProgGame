#include <iostream>
#include <vector>
using namespace std;

class Tile {
    public:
        bool isCovered;
        int adjacentBombs;
        bool isBomb;
        bool isFlagged;
        Tile() {
            isCovered = true;
            adjacentBombs = 0;
            isBomb = false;
            isFlagged = false;
        }
};

/*------------------
---- PROTOTYPES ----
------------------*/

vector<vector<Tile>> createGrid(int aBombCount, int aGridSize);

void startUp();

void printGrid();

void input();

void gameOver();

void revealTile(int** grid,int posX, int posY);

void blankHandling();

/*------------------
----    MAIN    ----
------------------*/

int main(){
    int bombCount{15};
    int gridSize{5};
    auto grid = createGrid(bombCount, gridSize);

}

/*-------------------
----  FUNCTIONS  ----
-------------------*/

vector<vector<Tile>> createGrid(int aBombCount, int aGridSize){
    // Initialize Grid
    vector<vector<Tile>> grid;
    vector<Tile> column;
    Tile tile;
    for (int j{0};j<aGridSize;j++) {
        column.push_back(tile);
    }
    for (int i{0};i<aGridSize;i++) {
        grid.push_back(column);
    }

    // Initialize Bombs
    for (int i{0};i<aBombCount;i++) {
        int xPos{0};
        int yPos{0};
        do {
            xPos = rand() % (aGridSize);
            yPos = rand() % (aGridSize);
        } while (grid.at(xPos).at(yPos).isBomb);
        grid[xPos][yPos].isBomb = true;
    }
    return grid;
}

void startUp(){

}

void printGrid(){

}

void input(){

}

void gameOver(){

}

void revealTile(int** grid,int posX, int posY){
    // Not known how the grid will be organized, using forced data for now
    int bombCount = 0;
    for (int searchX{-1};searchX<1;searchX++) {
        for (int searchY{-1};searchY<1;searchY++) {
            if (grid[posX+searchX][posY+searchY]==-1) {
                bombCount++;
            }
        }
    }
    if (bombCount==0) {
        
    }
    grid[posX][posY] = bombCount;
}

void blankHandling(){
    
}
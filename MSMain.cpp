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

vector<vector<Tile>> createGrid();

void startUp();

void printGrid();

void input();

void gameOver();

void revealTile(int* grid,int posX, int posY);

void blankHandling();

/*------------------
----    MAIN    ----
------------------*/

int main(){
    auto grid = createGrid();

}

/*-------------------
----  FUNCTIONS  ----
-------------------*/

vector<vector<Tile>> createGrid(){
    vector<vector<Tile>> grid;
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
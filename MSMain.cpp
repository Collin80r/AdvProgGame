#include <iostream>
#include <vector>
#include <stdlib.h>
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

void revealTile();

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

    // Initialize Numbers
    for (int x{0};x<aGridSize;x++) {
        for (int y{0};y<aGridSize;y++) {
            if (!grid.at(x).at(y).isBomb) {
                int adjacentBombs{0};
                for (int xSearch{-1};xSearch<=1;xSearch++) {
                    for (int ySearch{-1};ySearch<=1;ySearch++) {
                        if ((x+xSearch > -1) && (y+ySearch > -1) && (x+xSearch < aGridSize) && (y+ySearch < aGridSize)) {
                            if (grid.at(x+xSearch).at(y+ySearch).isBomb){
                                adjacentBombs++;
                            }
                        }
                    }
                }
                grid.at(x).at(y).adjacentBombs = adjacentBombs;
            }
        }
    }
    return grid;
}

void startUp(){

}

void printGrid(){

}

void input(int gridSize){
    int option{0};
    int x{};
    int y{};
    cout<<"Options: \n(1) dig\n(2) place flag\n(3) remove flag"<<endl;
    cin>>option;
    cout<<"Give x and y coordinates separately: ";
    cin>>x>>y;
    if (((x < gridSize) && (x >= 0)) && ((y < gridSize) && (y >=0))){
        cout<<"yes"<<endl;
    }

}

void gameOver(){

}

void revealTile(){

}

void blankHandling(){
    
}
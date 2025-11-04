#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <variant>
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

void input(int);

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
    input(gridSize);
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
    int selection = 0;

    int x{0};
    int y{0};
    int valid{1};
    do{
        cout<<"Options: \n(1) dig\n(2) place flag\n(3) remove flag"<<endl;
        cin>>selection;

        if ((selection == 1) || (selection == 2) ||(selection == 3)){
            valid = 1;
        }else{
            valid = 0;
            cout<<"\nYour input was not in the given range. Pick 1, 2, or 3.\n";
        }
    } while (valid == 0);
    do{
        cout<<"x: ";
        cin>>x;
        cout<<"\ny: ";
        cin>>y;
        if (!(((x < gridSize) && (x >= 0)) && ((y < gridSize) && (y >=0)))){
            cout<<"\nInput out of bounds. Use x and y coordinates from 0 to "<<gridSize<<"."<<endl;
            valid = 0;
        }else{
            valid = 1;
        }
    } while (valid == 0);
    //now do the chekcing thingies
    
}

void gameOver(){

}

void revealTile(){

}

void blankHandling(){
    
}
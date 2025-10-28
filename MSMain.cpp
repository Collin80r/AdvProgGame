#include <iostream>
#include <vector>
#include <array>
#include <cmath>
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

void revealTile();

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

void printGrid(const array<Tile>& tiles){
    int rowSize = sqrt(tiles.size());
    int column = 0;
    for(const Tile& t : tiles){
        column++;
        if(t.isFlagged){
            cout << "F";
        }
        else if(t.covered){
            cout << "O";
        }
        else if(t.isBomb){
            cout << "X";
        }
        else if(t.adjacentBombs != 0){
            cout << t.adjacentBombs;
        }
        else{
            cout << " ";
        }
        if(column % rowSize == 0){
            cout << endl;
            column = 0;
        }
    }
}

void input(){

}

void gameOver(){

}

void revealTile(){

}

void blankHandling(){
    
}
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

void printGrid(){

}

void input(){

}

void gameOver(){

}

void revealTile(){

}

void blankHandling(){
    
}
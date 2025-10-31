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

void printGrid(const vector<vector<Tile>>& t){
    int rowSize = t.size();
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < rowSize; j++){
            if(t[i][j].isFlagged){
                cout << "F";
            }
            else if(t[i][j].isCovered){
                cout << "O";
            }
            else if(t[i][j].isBomb){
                cout << "X";
            }
            else if(t[i][j].adjacentBombs != 0){
                cout << t[i][j].adjacentBombs;
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
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
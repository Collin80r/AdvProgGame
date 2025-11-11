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

void printGrid(const vector<vector<Tile>> grid);

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
    printGrid(grid);

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

void printGrid(const vector<vector<Tile>> grid){
    int rowSize = grid.size();
    int numBombs = 0;
    cout << "   ";
    for(int i = 0; i < rowSize; i++){
        cout << i+1 << " ";
    }
    cout << endl;
    for(int i = 0; i < rowSize; i++){
        cout << i+1 << " ";
        cout << "\033[37;40m|\033[0m";
        for(int j = 0; j < rowSize; j++){
            //background white; text red
            if(grid[i][j].isFlagged){
                cout << "\033[4;47;31mF\033[0;37;40m|\033[0m";
            }
            //background white
            else if(grid[i][j].isCovered){
                cout << "\033[47m_\033[0;37;40m|\033[0m";
            }
            //background red; text black
            else if(grid[i][j].isBomb){
                cout << "\033[4;30;41mX\033[0;37;40m|\033[0m";
            }
            //different colors for different numbers
            else if(grid[i][j].adjacentBombs != 0){
                numBombs = grid[i][j].adjacentBombs;
                if(numBombs == 1 || numBombs == 5){//magenta
                    cout << "\033[4;35m"<<numBombs<<"\033[0;40m|\033[0m";
                }
                else if(numBombs == 2 || numBombs == 6){//blue
                    cout << "\033[4;34m"<<numBombs<<"\033[0;40m|\033[0m";
                }
                else if(numBombs == 3 || numBombs == 7){//yellow
                    cout << "\033[4;33m"<<numBombs<<"\033[0;40m|\033[0m";
                }
                else{//green
                    cout << "\033[4;32m"<<numBombs<<"\033[0;40m|\033[0m";
                }
            }
            //no background but need underline
            else{
                cout << "\033[4m \033[0m|";
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
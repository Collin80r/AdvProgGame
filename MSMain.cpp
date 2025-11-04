#include <iostream>
#include <vector>
#include <string>
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

vector<vector<Tile> > createGrid(int aBombCount, int aGridSize);

void startGame(int gridSize);

void mainMenu();

void printGrid(const vector<vector<Tile> > grid);

void input();

void gameOver();

void revealTile();

void blankHandling();

/*------------------
----    MAIN    ----
------------------*/

int main(){
    mainMenu();
    int bombCount{15};
    int gridSize{5};
    auto grid = createGrid(bombCount, gridSize);
    printGrid(grid);

}

/*-------------------
----  FUNCTIONS  ----
-------------------*/

// Placeholder function for Minesweeper game
void startGame(int gridSize) {
    cout << "\nStarting Minesweeper " << gridSize << "x" << gridSize << "...\n";
    cout << "Game logic not implemented yet.\n\n";

    // TODO: Implement actual Minesweeper game here
}

void mainMenu() {
    while (true) {
        // Intro blurb
        cout << "=======================================\n";
        cout << "         Welcome to Minesweeper!       \n";
        cout << " Solve the grid without hitting a mine!\n";
        cout << " Choose your difficulty and good luck!\n";
        cout << "=======================================\n\n";

        // Difficulty selection
        cout << "Select Difficulty Level:\n";
        cout << "1. Easy (4x4)\n";
        cout << "2. Medium (6x6)\n";
        cout << "3. Hard (9x9)\n";

        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        int gridSize;
        if (choice == 1) {
            gridSize = 4;
        } else if (choice == 2) {
            gridSize = 6;
        } else if (choice == 3) {
            gridSize = 9;
        } else {
            cout << "\nInvalid choice! Please select 1, 2, or 3.\n\n";
            continue; // Go back to menu
        }

        // Ask if they want to start the game
        string start;
        cout << "\nDo you want to start the " << gridSize << "x" << gridSize << " game? (yes/no): ";
        cin >> start;

        if (start == "yes" || start == "y" || start == "Y" || start == "Yes") {
            startGame(gridSize);
            cout << "Press Enter to return to main menu...";
            cin.ignore(); // To ignore leftover newline
            cin.get();    // Wait for Enter
        } else {
            cout << "\nReturning to main menu...\n\n";
        }
    }
}

vector<vector<Tile> > createGrid(int aBombCount, int aGridSize){
    // Initialize Grid
    vector<vector<Tile> > grid;
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

void printGrid(const vector<vector<Tile> > grid){
    int rowSize = grid.size();
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < rowSize; j++){
            if(grid[i][j].isFlagged){
                cout << "F";
            }
            else if(grid[i][j].isCovered){
                cout << "O";
            }
            else if(grid[i][j].isBomb){
                cout << "X";
            }
            else if(grid[i][j].adjacentBombs != 0){
                cout << grid[i][j].adjacentBombs;
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
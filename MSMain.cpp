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

bool checkWin(const vector<vector<Tile> > aGrid);

vector<vector<Tile> > createGrid(int aBombCount, int aGridSize);

void startGame(int gridSize);

int mainMenu();

void printGrid(const vector<vector<Tile> > grid);

void input(vector<vector<Tile>>& grid);

void gameOver();

void revealTile(vector<vector<Tile>>& aGrid, int x, int y);

void blankHandling();

/*------------------
----    MAIN    ----
------------------*/

int main(){
    int gridSize{0};
    gridSize = mainMenu();
    int bombCount{15};
    auto grid = createGrid(bombCount, gridSize);
    bool endGame = false;
    while (!endGame) {
        printGrid(grid);
        input(grid);
        endGame = checkWin(grid);
    }

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

int mainMenu() {
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
            return gridSize;
        } else {
            cout << "\nReturning to main menu...\n\n";
        }
    }
}

bool checkWin(const vector<vector<Tile> > aGrid){
    bool gameWon{true};
    int aGridSize = aGrid.size();
    for (int x{0};x<aGridSize;x++) {
        for (int y{0};y<aGridSize;y++) {
            const auto tile = aGrid.at(x).at(y);
            if (!tile.isBomb && tile.isCovered) {
                gameWon = false;
            }
        }
    }
    return gameWon;
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

void input(vector<vector<Tile>>& grid){
    int selection = 0;
    int gridSize = grid.size();

    int xInput{0};
    int yInput{0};
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
        cin>>xInput;
        cout<<"\ny: ";
        cin>>yInput;
        if (!(((xInput < gridSize) && (xInput >= 0)) && ((yInput < gridSize) && (yInput >= 0)))){
            cout<<"\nInput out of bounds. Use x and y coordinates from 0 to "<<gridSize<<"."<<endl;
            valid = 0;
        }else{
            valid = 1;
        }
    } while (valid == 0);
    if (selection == 1){//dig
        if (grid.at(yInput).at(xInput).isBomb == true){
            gameOver();
        }else{
            revealTile(grid, xInput, yInput);
        }
    }
    if (selection == 2){//flag
        grid.at(yInput).at(xInput).isFlagged = true;
    }
    if (selection == 3){//unflag
        grid.at(yInput).at(xInput).isFlagged = false;
    }
}

void gameOver(){
    cout << "BOOM!" << endl;
}

void revealTile(vector<vector<Tile>>& aGrid, int x, int y){
    int aGridSize = aGrid.size();
    aGrid.at(y).at(x).isCovered = false;
    if (aGrid.at(y).at(x).adjacentBombs == 0) {
        for (int ySearch{-1};ySearch<=1;ySearch++) {
            for (int xSearch{-1};xSearch<=1;xSearch++) {
                if ((x+xSearch > -1) && (y+ySearch > -1) && (x+xSearch < aGridSize) && (y+ySearch < aGridSize)) {
                    if (aGrid.at(y+ySearch).at(x+xSearch).isCovered) {
                        revealTile(aGrid, x+xSearch, y+ySearch);
                    }
                }
            }
        }
    }
}
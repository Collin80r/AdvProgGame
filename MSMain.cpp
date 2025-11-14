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

enum gameState {
    WIN,
    LOSE,
    CONTINUE,
};

/*------------------
---- PROTOTYPES ----
------------------*/

gameState checkEnd(const vector<vector<Tile>> aGrid);

vector<vector<Tile>> createGrid(int aGridSize);

void randomizeGrid(vector<vector<Tile>>& aGrid, int aBombCount, int xInput, int yInput);

void startGame(int gridSize);

int mainMenu();

void printGrid(const vector<vector<Tile>> grid);

void input(vector<vector<Tile>>& grid, int turn, int bombCount);

void gameOver(long startTime, int bombCount, int correctFlagCount);

void revealTile(vector<vector<Tile>>& aGrid, int x, int y);

long checkTime(long startTime);

/*------------------
----    MAIN    ----
------------------*/

int main(){
    srand(static_cast<unsigned int>(time(0)));
    bool playAgain{true};
    while (playAgain) {
        time_t startTime;
        time(&startTime);

        int gridSize{0};
        gridSize = mainMenu();
        int bombCount = gridSize*gridSize * 0.126;
        auto grid = createGrid(gridSize);
        gameState endGame{CONTINUE};
        int turn{0};
        while (endGame == CONTINUE) {
            turn++;
            printGrid(grid);
            input(grid, turn, bombCount);
            endGame = checkEnd(grid);
        }
        printGrid(grid);
        if (endGame == WIN) {
            cout << "\n=======================================\n";
            cout << "        CONGRATULATIONS! YOU WIN!        \n";
            cout << "=========================================\n";
            cout << "Completed in " << checkTime(startTime) << " seconds\n";
        } else {
            int correctFlagCount{0};
            for (int i{0};i<gridSize;i++) {
                for (int j{0};j<gridSize;j++) {
                    if (grid.at(i).at(j).isBomb && grid.at(i).at(j).isFlagged) {
                        correctFlagCount++;
                    }
                }
            }

            cout << "\n=======================================\n";
            cout << "           BOOM!   GAME OVER!            \n";
            cout << "=========================================\n";

            cout << correctFlagCount << "/" << bombCount << " bombs found\n";
            cout <<checkTime(startTime) << " seconds wasted\n";
            cout << "---------------------------------------\n";

        }
        string choice;
        cout << "Would you like to play again? (yes/no): ";
        cin >> choice;
        if (choice == "yes" || choice == "y" || choice == "Y" || choice == "Yes") {
            cout << "\nReturning to start menu...\n\n";
        } else {
            cout << "\nThanks for playing Minesweeper!\n";
            cout << "Goodbye!\n";
            playAgain = false;
        }
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

gameState checkEnd(const vector<vector<Tile> > aGrid){
    gameState endGame{WIN};
    int aGridSize = aGrid.size();
    for (int x{0};x<aGridSize;x++) {
        for (int y{0};y<aGridSize;y++) {
            const auto tile = aGrid.at(x).at(y);
            if ((!tile.isBomb && tile.isCovered)) { // Keep going
                endGame = CONTINUE;
            }
            if ((tile.isBomb && !tile.isCovered)) { // Fail Condition
                endGame = LOSE;
                return endGame;
            }
        }
    }
    return endGame;
}

vector<vector<Tile> > createGrid(int aGridSize){
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
    return grid;
}

void randomizeGrid(vector<vector<Tile>>& aGrid, int aBombCount, int xInput, int yInput){
    int gridSize = aGrid.size();
    do {
        for (int i{0};i<gridSize;i++){
            for (int j{0};j<gridSize;j++) {
                aGrid.at(i).at(j).adjacentBombs = 0;
                aGrid.at(i).at(j).isBomb = 0;
            }
        }
        // Initialize Bombs
        for (int i{0};i<aBombCount;i++) {
            int xPos{0};
            int yPos{0};
            do {
                xPos = rand() % (gridSize);
                yPos = rand() % (gridSize);
            } while (aGrid.at(yPos).at(xPos).isBomb);
            aGrid[yPos][xPos].isBomb = true;
            aGrid[yPos][xPos].adjacentBombs = 0;
        }

        // Initialize Numbers
        for (int y{0};y<gridSize;y++) {
            for (int x{0};x<gridSize;x++) {
                if (!aGrid.at(y).at(x).isBomb) {
                    int adjacentBombs{0};
                    for (int ySearch{-1};ySearch<=1;ySearch++) {
                        for (int xSearch{-1};xSearch<=1;xSearch++) {
                            if ((x+xSearch > -1) && (y+ySearch > -1) && (x+xSearch < gridSize) && (y+ySearch < gridSize)) {
                                if (aGrid.at(y+ySearch).at(x+xSearch).isBomb){
                                    adjacentBombs++;
                                }
                            }
                        }
                    }
                    aGrid.at(y).at(x).adjacentBombs = adjacentBombs;
                }
            }
        }
    } while (aGrid.at(yInput).at(xInput).adjacentBombs != 0 || aGrid.at(yInput).at(xInput).isBomb);
}

void printGrid(const vector<vector<Tile> > grid){
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

void input(vector<vector<Tile>>& grid, int turn, int bombCount){
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
        xInput--;
        cout<<"\ny: ";
        cin>>yInput;
        yInput--;
        if (!(((xInput < gridSize) && (xInput >= 0)) && ((yInput < gridSize) && (yInput >= 0)))){
            cout<<"\nInput out of bounds. Use x and y coordinates from 0 to "<<gridSize<<"."<<endl;
            valid = 0;
        }else{
            valid = 1;
        }
    } while (valid == 0);
    if (selection == 1){//dig
        if (turn==1) {
            randomizeGrid(grid, bombCount, xInput, yInput);
        }
        revealTile(grid, xInput, yInput);
    }
    if (selection == 2){//flag
        grid.at(yInput).at(xInput).isFlagged = true;
    }
    if (selection == 3){//unflag
        grid.at(yInput).at(xInput).isFlagged = false;
    }
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

long checkTime(long startTime){//call this, Antonio. it gives time in seconds //checkTime(startTime);
    time_t currentTime;
    time(&currentTime);
    return(currentTime - startTime);
}

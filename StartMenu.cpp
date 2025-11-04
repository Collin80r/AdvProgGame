#include <iostream>
#include <string>

using namespace std;

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

int main() {
    mainMenu();
    return 0;
}

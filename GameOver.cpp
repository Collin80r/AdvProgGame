#include <iostream>
#include <string>

using namespace std;
void mainMenu();

void gameOverMenu(bool gameWon, bool isBomb) {
    cout << "\n=======================================\n";
    cout << "             GAME OVER                 \n";
    cout << "=======================================\n";
    cout << "Total Bombs: " << isBomb << "\n";
    cout << "Bombs Hit:   " << gameWon << "\n";
    cout << "---------------------------------------\n";

    string choice;
    cout << "Would you like to play again? (yes/no): ";
    cin >> choice;

    if (choice == "yes" || choice == "y" || choice == "Y" || choice == "Yes") {
        cout << "\nReturning to start menu...\n\n";
        mainMenu(); // Go back to start menu
    } else {
        cout << "\nThanks for playing Minesweeper!\n";
        cout << "Goodbye!\n";
        exit(0); // End the program
    }
}


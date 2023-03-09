// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

#define N 9

int grid[N][N];
int gridtoSolve[N][N];

//how to create masks

int gridMasking() { // It will return the numbers according to level of hardness
    //It will be improved in time
    // 3 hardness level
    // A least 3 pattern in every hardness level

    int emptyNumbers = 0; // It will contain the numbers according to level of hardness
    emptyNumbers = 46; // For this time it will be 
    //These patterns decide which numbers will be shown to the player
    int gridMask[9][9] = { {1, 0, 1, 1, 0, 0, 1, 0, 0}, //4
                      {0, 0, 1, 0, 0, 1, 0, 1, 1}, //4
                      {0, 0, 1, 0, 1, 0, 1, 1, 0}, //4
                      {1, 0, 0, 1, 0, 1, 0, 0, 0}, //3
                      {0, 0, 1, 1, 1, 0, 1, 0, 0}, //4
                      {0, 1, 0, 1, 0, 1, 0, 1, 0}, //4
                      {1, 0, 0, 0, 1, 0, 0, 1, 1}, //4
                      {1, 0, 1, 0, 1, 0, 1, 0, 0}, //4
                      {0, 1, 0, 0, 1, 1, 0, 0, 1} }; //4
                                                   //Total: 35 numbers are given, 46 numbers are empty
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            gridtoSolve[row][col] = gridtoSolve[row][col] * gridMask[row][col];
        }
    }
    return emptyNumbers;
}


int boxFinder(int row, int col) {
    int boxNumber = 0;
    if (col < 4) {
        if (row < 4) {
            boxNumber = 1;
        }
        if (row > 3 && row < 7) {
            boxNumber = 2;
        }
        if (row > 6) {
            boxNumber = 3;
        }
    }
    if (col > 3 && col < 7) {
        if (row < 4) {
            boxNumber = 4;
        }
        if (row > 3 && row < 7) {
            boxNumber = 5;
        }
        if (row > 6) {
            boxNumber = 6;
        }
    }
    if (col > 6) {
        if (row < 4) {
            boxNumber = 7;
        }
        if (row > 3 && row < 7) {
            boxNumber = 8;
        }
        if (row > 6) {
            boxNumber = 9;
        }
    }

    return boxNumber;
}

void showGridtoSolve() {
    int countColumn = 0;
    int countRow = 0;

    cout << "\n\n\n";
    cout << "     " << "1   2   3     4   5   6     7   8   9\n"; //column guide numbers
    cout << "     " << "-   -   -     -   -   -     -   -   -\n\n";
    for (int i = 0; i < 9; i++) {
        countRow++;
        cout << i + 1 << " | "; // row guide numbers
        for (int j = 0; j < 9; j++) {
            countColumn++;
            //if ((countColumn % 3) != 1) {
            //    cout << "| ";
            //}
            if (gridtoSolve[i][j] == 0) {
                cout << " " << "." << "  ";
            }
            else {
                cout << " " << gridtoSolve[i][j] << "  ";
            }
            if ((countColumn % 3) == 0) {
                cout << "  ";
            }

        }
        if ((countRow % 3) == 0) {
            cout << "\n";
            //cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << "\n";
        }
        else {
            //cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << "\n";
        }
    }
}


void showGrid() {
    int countColumn = 0;
    int countRow = 0;
    cout << "\n\n\n";
    for (int i = 0; i < 9; i++) {
        countRow++;
        for (int j = 0; j < 9; j++) {
            countColumn++;
            if ((countColumn % 3) != 1) {
                cout << "| ";
            }
            cout <<" " << grid[i][j] << "  ";
            if ((countColumn%3)==0) {
                cout << "  ";
            }

        }
        if ((countRow % 3) == 0) {
            cout << "\n";
            //cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << "\n";
        }
        else {
            //cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
            cout << "\n";
        }
    }
}


void fillGrid()//int thisGrid[9][9]) 
{
    //First create an array filled with random numbers 1-9
    srand(time(0));
    int randomNumber = 0;
    int randomArray[9] = { 0 };
    int flagArray[10] = { 0 };

    for (int t = 0; t < 9; t++) {
    tryAgain:
        randomNumber = (rand() % 9) + 1;
        if (flagArray[randomNumber] == 0) {
            randomArray[t] = randomNumber;
            flagArray[randomNumber] = 1;
        }
        else {
            goto tryAgain;
        }

    }

    for (int t = 0; t < 9; t++)
    {
        cout << randomArray[t] << " ";
    }
    cout << "\n\n";

    //Now create our grid

    int flagColumn[10][10] = { 0 };
    int flagRow[10][10] = { 0 };
    int flagBox[10][10] = { 0 };
    int boxNumber = 1;

    bool foundNumber = false;
    int index = 0;

    for (int row = 1; row < 10; row++) {
        for (int col = 1; col < 10; col++) {
            foundNumber = false;
            boxNumber = boxFinder(row, col);
            while (!foundNumber) {

                if (flagColumn[col][randomArray[index]] == 0 && flagRow[row][randomArray[index]] == 0 && flagBox[boxNumber][randomArray[index]] == 0) {
                    //cout << randomArray[index] << "  ";
                    flagColumn[col][randomArray[index]] = 1;
                    flagRow[row][randomArray[index]] = 1;
                    flagBox[boxNumber][randomArray[index]] = 1;
                    grid[row - 1][col - 1] = randomArray[index];
                    gridtoSolve[row - 1][col - 1] = randomArray[index];
                    foundNumber = true;
                }
                index++; //Look for other number
                if (index == 9) {
                    index = 0; // look for begining again
                }
            }

        }
        //cout << "\n";
    }


}

int main()
{
    playAgain:
    int lives = 3;
    int numberToFind = 0;
    string choice;
    int inputRow = 0;
    int inputCol = 0;
    int inputGuess = 0;
    fillGrid();
    showGrid();
    numberToFind = gridMasking(); // It will contain the numbers according to level of hardness
    showGridtoSolve();
    

    //Now it is time to create the UI
    cout << "\nWelcome to our sudoku game";

    while (lives!=0) { // Our game loop
        if (numberToFind == 0) { //If there are no more numbers to find, finish the game
            cout << "\n\n\n\t\t\tCongartulations!! You won!";
            cout << "\nIf you want to play again press 'y' or 'Y' and press Enter. Otherwise press any other key and press Enter:  ";
            cin >> choice;
            if (choice == "y" || choice == "Y") {
                goto playAgain;
            }
            goto finish;
        }
        cout << "\n\nYou have " << lives << " lives";
        cout << "\nMake your guess in this order pls; row - column - answer\n";
        cin >> inputRow >> inputCol >> inputGuess; //Take the input as in asked Order
        //First we need to check if the given row-col is empty?
        if (gridtoSolve[inputRow-1][inputCol-1] != 0) {
            cout << "\nThe element you choose is already full! Please try again. \n";
            continue; // skip this iteration of the loop to try again
        }
        if (grid[inputRow-1][inputCol-1] == inputGuess) { // if the input is right 
            numberToFind--; 
            gridtoSolve[inputRow-1][inputCol-1] = inputGuess; //Add the correct answer
            showGridtoSolve(); // Show our grid with the correct answer
            cout << "\nCorrect!\n"; // Feedback
        }
        else {
            cout << "\nWrong!\n";
            lives--;
        }
        
    }

    cout << "\n\nYou are out of lives. If you want to play again, then press 'y' or 'Y'. Otherwise press any other key. "; 
    cin >> choice;
    if (choice == "y" || choice == "Y") {
        goto playAgain;
    }
    finish:
    return 0;
}

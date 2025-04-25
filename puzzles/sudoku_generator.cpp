#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to print the Sudoku grid in the desired format
void printBoard(int board[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                cout << ". ";  // Empty cell represented by "."
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Check if it's safe to place a number in a given position
bool isSafe(int board[9][9], int row, int col, int num) {
    // Check the row and column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    
    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Backtracking solver to fill the Sudoku board
bool solve(int board[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve(board)) {
                            return true;
                        }
                        board[row][col] = 0; // Backtrack
                    }
                }
                return false;
            }
        }
    }
    return true; // Puzzle solved
}

// Helper to fill a 3x3 box with random numbers 1-9
void fillBox(int board[9][9], int row, int col) {
    int num;
    bool used[10] = {false};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            do {
                num = rand() % 9 + 1;
            } while (used[num]);
            used[num] = true;
            board[row + i][col + j] = num;
        }
    }
}

// Function to generate the Sudoku puzzle
void generateSudoku(int board[9][9]) {
    // Fill the board with 0s
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }

    // Randomly fill diagonal 3x3 boxes
    fillBox(board, 0, 0);
    fillBox(board, 3, 3);
    fillBox(board, 6, 6);

    // Solve the Sudoku to get a valid board
    solve(board);
}

// Function to remove numbers based on difficulty level
void removeNumbers(int board[9][9], int level) {
    int totalCells = 81;
    int cellsToRemove = 0;
    
    switch (level) {
        case 1: cellsToRemove = totalCells * 0.3; break; // Easy (30% removed)
        case 2: cellsToRemove = totalCells * 0.4; break; // Medium (40% removed)
        case 3: cellsToRemove = totalCells * 0.5; break; // Hard (50% removed)
        case 4: cellsToRemove = totalCells * 0.6; break; // Very Hard (60% removed)
        case 5: cellsToRemove = totalCells * 0.7; break; // Extreme (70% removed)
    }

    // Randomly remove numbers
    while (cellsToRemove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0; // Remove number
            cellsToRemove--;
        }
    }
}

// Function to write the puzzle to a file
void writePuzzleToFile(int board[9][9], int puzzleIndex) {
    ofstream outFile("puzzle_" + to_string(puzzleIndex) + ".txt");
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                outFile << ". ";  // Empty cell represented by "."
            } else {
                outFile << board[i][j] << " ";
            }
        }
        outFile << endl;
    }
    outFile.close();
}

int main(int argc, char *argv[]) {
    srand(time(0)); // Seed for randomness

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <number of puzzles> <difficulty (1-5)>" << endl;
        return 1;
    }

    int numPuzzles = atoi(argv[1]);
    int difficulty = atoi(argv[2]);

    if (difficulty < 1 || difficulty > 5) {
        cout << "Difficulty level must be between 1 and 5." << endl;
        return 1;
    }

    for (int i = 0; i < numPuzzles; ++i) {
        int board[9][9];
        generateSudoku(board);
        removeNumbers(board, difficulty);
        writePuzzleToFile(board, i + 1);
        cout << "Puzzle " << i + 1 << " generated." << endl;
    }

    return 0;
}
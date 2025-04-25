#include "solver.hpp"

namespace {
    // Helper function to check if it's safe to place num at (row, col)
    bool isSafe(const SudokuBoard& board, int row, int col, int num) {
        return board.isSafe(row, col, num);
    }

    // Recursive solver function
    bool solveSudokuRec(SudokuBoard& board, int row, int col) {
        if (row == 8 && col == 9)
            return true;
        if (col == 9)
            return solveSudokuRec(board, row + 1, 0);
        if (!board.isEmpty(row, col))
            return solveSudokuRec(board, row, col + 1);

        for (int num = 1; num <= 9; ++num) {
            if (isSafe(board, row, col, num)) {
                board.set(row, col, num);
                if (solveSudokuRec(board, row, col + 1))
                    return true;
                board.set(row, col, 0);
            }
        }
        return false;
    }
}

bool SudokuSolver::solve(SudokuBoard& board) {
    return solveSudokuRec(board, 0, 0);
}
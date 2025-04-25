#include "board.hpp"
#include "solver.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    SudokuBoard board;
    SudokuSolver solver;

    if (argc != 2) {
        std::cerr << "Usage: ./sudoku_solver puzzles/example.txt\n";
        std::cerr << "Please provide a puzzle file from the 'puzzles' folder.\n";
        return 1;
    }

    if (!board.loadFromFile(argv[1])) {
        std::cerr << "Failed to load puzzle\n";
        return 1;
    }

    std::cout << "Original Puzzle:\n";
    board.print();

    if (solver.solve(board)) {
        std::cout << "Solved Puzzle:\n";
        board.print();
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}

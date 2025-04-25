#include "board.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

SudokuBoard::SudokuBoard() : grid(9, std::vector<int>(9, 0)) {}

bool SudokuBoard::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int row = 0;
    while (std::getline(file, line) && row < 9) {
        std::stringstream ss(line);
        for (int col = 0; col < 9; ++col) {
            char ch;
            ss >> ch;
            grid[row][col] = (ch == '.' || ch == '0') ? 0 : ch - '0';
        }
        ++row;
    }
    return row == 9;
}

bool SudokuBoard::loadFromString(const std::string& input) {
    std::stringstream ss(input);
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j) {
            char ch;
            ss >> ch;
            grid[i][j] = (ch == '.' || ch == '0') ? 0 : ch - '0';
        }
    return true;
}

void SudokuBoard::print() const {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) std::cout << "-------------------------\n";
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) std::cout << "| ";
            std::cout << (grid[i][j] ? std::to_string(grid[i][j]) : ".") << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "-------------------------\n";
}

bool SudokuBoard::isSafe(int row, int col, int num) const {
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }
    int r0 = row - row % 3, c0 = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[r0 + i][c0 + j] == num)
                return false;
    return true;
}

void SudokuBoard::set(int row, int col, int num) {
    grid[row][col] = num;
}

int SudokuBoard::get(int row, int col) const {
    return grid[row][col];
}

bool SudokuBoard::isEmpty(int row, int col) const {
    return grid[row][col] == 0;
}

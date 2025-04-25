#pragma once
#include <vector>
#include <string>

class SudokuBoard {
public:
    SudokuBoard();
    bool loadFromFile(const std::string& filename);
    bool loadFromString(const std::string& input);
    void print() const;
    bool isSafe(int row, int col, int num) const;
    void set(int row, int col, int num);
    int get(int row, int col) const;
    bool isEmpty(int row, int col) const;

private:
    std::vector<std::vector<int>> grid;
};

# Sudoku Generator & Solver

This project provides a command-line Sudoku puzzle generator and solver written in C++. It includes tools to generate puzzles of varying difficulty and to solve puzzles from text files.

## Features

- **Sudoku Puzzle Generator**  
  Generates random Sudoku puzzles with selectable difficulty (easy to extreme). Outputs puzzles to text files.

- **Sudoku Solver**  
  Solves standard 9x9 Sudoku puzzles from text files. Uses a backtracking algorithm.

- **Modular Codebase**  
  Clean separation between board representation, solver logic, and puzzle generation.

## Project Structure

```
.
├── board.hpp / board.cpp      # Sudoku board representation and utilities
├── solver.hpp / solver.cpp    # Sudoku solving logic
├── main.cpp                   # Command-line interface for solving puzzles
├── puzzles/
│   ├── sudoku_generator.cpp   # Puzzle generator tool
│   └── example.txt            # Example puzzle file
└── README.md                  # Project documentation
```

## Building

You need a C++ compiler (e.g., g++, clang++).

**To build the solver:**
```sh
g++ *.cpp -o sudoku_solver
```

**To build the generator:**
```sh
g++ sudoku_generator.cpp -o sudoku_generator
```

## Usage

### Generate Puzzles

Generate N puzzles of a given difficulty (1=easy, 5=extreme):

```sh
./sudoku_generator <number_of_puzzles> <difficulty>
# Example:
./sudoku_generator 5 3
```
Puzzles will be saved as `puzzle_1.txt`, `puzzle_2.txt`, etc.

### Solve a Puzzle

Solve a puzzle from a text file (see format below):

```sh
./sudoku_solver example.txt
```

## Puzzle File Format

Each puzzle is a 9x9 grid. Use numbers 1-9 for filled cells and `.` or `0` for empty cells. Example:

```
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```
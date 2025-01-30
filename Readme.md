# Sudoku Game in C

## Description

This is a console-based Sudoku game implemented in C. The game allows the user to either play with a predefined Sudoku board or input their own board and solve it step by step.

## Features

- Choose between a predefined Sudoku puzzle or input your own.
- Ensures that the Sudoku rules are followed for each move.
- Provides validation to check if the board is correct.
- Displays the Sudoku board in a structured format.

## Files

- `main.c` - Entry point of the program.
- `sudoku.h` - Header file containing function declarations and constants.
- `sudoku.c` - Contains the game logic, including validation and display functions.

## How to Compile

Use the following command to compile the program using `gcc`:

```bash
gcc main.c sudoku.c -o sudoku

How to Play
   Choose whether to play with a predefined board or input your own.
   If choosing predefined, select difficulty (Easy, Medium, Hard).
   If inputting your own, enter numbers row by row (use 0 for empty cells).
   Enter row, column, and the number to place in the Sudoku grid.
   The game will validate your input and update the board.
   Continue until the Sudoku is solved.

Validations Implemented
   Ensures numbers entered are between 1-9.
   Checks that the same number does not appear in the same row, column, or 3x3 box.
   If an invalid input is detected, the user is prompted to re-enter the value.

Future Improvements
   Add a graphical user interface.
   Implement a Sudoku solver to help users.

Author
   Developed by Grigor Mkhitaryan

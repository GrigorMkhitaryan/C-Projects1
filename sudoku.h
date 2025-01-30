#ifndef SUDOKU_H
#define SUDOKU_H

#define SIZE 9

void run();
void level_maker();
void display_sudoku();
void initialize_sudoku(int level);
void check(int (*arr)[SIZE], int i, int j, int num);
void smallmatrix(int (*arr)[SIZE], int i, int j, int num);
void user_input_sudoku();
int is_valid_move(int (*arr)[SIZE], int i, int j, int num);

#endif // SUDOKU_H

#ifndef SUDOKU_C
#define SUDOKU_C

#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

int arr[SIZE][SIZE] = {};
int count = 0;
int count1 = SIZE * SIZE;

void smallmatrix(int (*arr)[SIZE], int i, int j, int num) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (arr[i + x][j + y] == num) count++;
        }
    }
}

void check(int (*arr)[SIZE], int i, int j, int num) {
    for (int index = 0; index < SIZE; ++index) {
        if (arr[i][index] == num || arr[index][j] == num) count++;
    }
}

void initialize_sudoku(int level) {
    if (level == 1) {
        arr[0][2] = 1; arr[1][1] = 2; arr[2][0] = 3;
        arr[4][1] = 4; arr[4][4] = 5; arr[4][7] = 6;
        arr[7][1] = 5; arr[6][8] = 7; arr[7][7] = 8;
        arr[8][6] = 9;
    } else if (level == 2) {
        arr[0][1] = 4; arr[0][7] = 7; arr[1][3] = 5;
        arr[1][7] = 8; arr[1][8] = 1; arr[2][3] = 9;
        arr[2][4] = 3; arr[2][5] = 6; arr[3][7] = 1;
        arr[3][8] = 9; arr[4][0] = 5; arr[4][8] = 7;
        arr[5][0] = 7; arr[5][1] = 9; arr[6][4] = 6;
        arr[6][5] = 7; arr[7][0] = 6; arr[7][3] = 4;
        arr[7][5] = 8; arr[8][1] = 7; arr[8][7] = 6;
    } else if (level == 3) {
        arr[0][0] = 5; arr[0][1] = 3; arr[0][4] = 7;
        arr[1][0] = 6; arr[1][3] = 1; arr[1][4] = 9;
        arr[1][5] = 5; arr[2][1] = 9; arr[2][2] = 8;
        arr[2][7] = 6; arr[3][0] = 8; arr[3][4] = 6;
        arr[3][8] = 3; arr[4][0] = 4; arr[4][3] = 8;
        arr[4][5] = 3; arr[4][8] = 1; arr[5][0] = 7;
        arr[5][4] = 2; arr[5][8] = 6; arr[6][1] = 6;
        arr[6][6] = 2; arr[6][7] = 8; arr[7][3] = 4;
        arr[7][4] = 1; arr[7][5] = 9; arr[7][8] = 5;
        arr[8][4] = 8; arr[8][7] = 7; arr[8][8] = 9;
    }
}

int is_valid_move(int (*arr)[SIZE], int i, int j, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (arr[i][x] == num || arr[x][j] == num) {
            return 0;
        }
    }
    int startRow = (i / 3) * 3, startCol = (j / 3) * 3;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (arr[startRow + x][startCol + y] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int validate_sudoku(int (*arr)[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = arr[i][j];
            if (num != 0) {
                arr[i][j] = 0; // Temporarily clear to check validity
                if (!is_valid_move(arr, i, j, num)) {
                    arr[i][j] = num; // Restore value before returning
                    return 0;
                }
                arr[i][j] = num;
            }
        }
    }
    return 1;
}

void user_input_sudoku() {
    printf("Enter your Sudoku table row by row (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num;
            do {
                printf("Enter value for cell [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &num);
                if (num < 0 || num > 9) {
                    printf("Invalid input! Enter a valid number between 0 and 9.\n");
                }
            } while (num < 0 || num > 9);
            arr[i][j] = num;
        }
    }
    if (!validate_sudoku(arr)) {
        printf("Invalid Sudoku board! Please re-enter a valid Sudoku.");
        user_input_sudoku();
    }    
    
}

void display_sudoku() {
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0) printf(" -------- -------- -------\n");
        printf("| ");
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", arr[i][j]);
            if (j % 3 == 2) printf(" | ");
        }
        printf("\n");
    }
    printf(" -------- -------- -------\n");
}

void level_maker() {
    int choice;
    printf("Enter 1 for default Sudoku or 2 to input your own: ");
    scanf("%d", &choice);
    if (choice == 1) {
        int level;
        printf("Enter difficulty level (1-Hard, 2-Medium, 3-Easy): ");
        scanf("%d", &level);
        initialize_sudoku(level);
    } else {
        user_input_sudoku();
    }
}

void run() {
    level_maker();
    while (count1 > 0) {
        display_sudoku();
        int i, j, num;
        printf("Enter row, column, and number: ");
        scanf("%d %d %d", &i, &j, &num);
        if (arr[i][j] != 0) {
            printf("This cell already has a value. Try again.\n");
            continue;
        }
        check(arr, i, j, num);
        if (count == 0) {
            arr[i][j] = num;
            count1--;
        } else {
            printf("Invalid number. Try again.\n");
            count = 0;
        }
    }
    printf("You solved the Sudoku!\n");
}

#endif //SUDOKU_C

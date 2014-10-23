#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define ILLEGAL_STATE 1
#define GOAL_STATE    2
#define INCOMPLETE_STATE   0

int indexCal(int n, int row, int col);
void bubblesort(int * subboard, int size);
int CheckSudoku(int n, int *board, int indicator);
int SolveSudoku(int n, int *board, int indicator);

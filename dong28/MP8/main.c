#include <stdio.h>
#include <stdlib.h>
#include "mp8.h"
#include <math.h>
int main(int argc, char **argv) {
    int i, n, indicator;
    FILE * in;
    if(argv[1]== NULL) {
        printf("You need a input file.\n");
        return -1;
    }
    in = fopen(argv[1], "r");
    if(in == NULL) {
        return -1;
    }
    fscanf(in, "%d", &n);

    fscanf(in, "%d", &indicator);


    //board has size n*n by n*n
    //create the initial board from the input file
    int *board=(int *)malloc(n*n*n*n*sizeof(int));
    for(i=0; i<(n*n*n*n);i++)
        fscanf(in, "%d", &board[i]);

    //Solve the Sudoku
    if (SolveSudoku(n,board,indicator))
    {
    //print out the solution
    for (i=0;i<(n*n*n*n);i++)
        printf("%d%c", board[i],((i+1)%(n*n))?' ':'\n');
    free(board);
    return 0;}

    printf("cannot solve the puzzle\n");
    return 0;
}

#include "mp8.h"
#include <math.h>
/*This function calcuates the index of a given cell in the board */
/*n is the size of the sub-region                                */
/* row and col are the coordinates of the cell                   */
int indexCal(int n, int row, int col) {
    return 0;
}


 
/*Bubble sort is a sorting algorithm that sorts a given array    */
/*subboard is the array pointer, size is the size of the array   */
void bubblesort(int * subboard, int size) {
    int i,temp,swap;
    do {
        swap = 0;
       
        }
    } while(swap);
}



/*Check if Sudoku board is valid                                                    */
/*return ILLEGAL_STATE when you have two same number in a row, or col or sub-region */
/*reutrn INCOMPLETE_STATE when the board is not completely filled with valid numbers     */
/*return GOAL_STATE if the board is solved                                          */
int CheckSudoku(int n, int *board, int indicator) {
    int i, j;
    //copy is used as a temp array to store a row, or col, or sub-region of numbers.
    //the memory for copy is dynamically allocated
    int * copy = malloc(n*n*sizeof(int));

    //check each row, colum and sub-region for duplicates
    //copy the row, colum or sub-region to the array named copy 
    //sort copy with bubble sort and then check for duplicates
    
  
    //check the diagonals if indicator is 1

   
    //If there is no duplicates in the board, check if the board is complete

    //else the board is complete and valid, thus we found the solution.

}



/* This function solves the board with recursion                             */
/* Base case is when you have GOAL_STATE and ILLEGAL_STATE                  */
int SolveSudoku(int n, int *board,int indicator) {
    int p, g=(n*n)+1;
    switch(CheckSudoku(n,board,indicator)) {
        case GOAL_STATE: return 1;
        case ILLEGAL_STATE: return 0;
    }
    
    
}



#include "mp8.h"
#include <math.h>

/*This function calcuates the index of a given cell in the board */
/*n is the size of the sub-region                                */
/* row and col are the coordinates of the cell                   */
int indexCal(int n, int row, int col) {
	return (n*n*row + col) ; 
}


 
/*Bubble sort is a sorting algorithm that sorts a given array    */
/*subboard is the array pointer, size is the size of the array   */
void bubblesort(int * subboard, int size) {
    int i,temp,swap;
    do {
        swap = 0;
        for(i=0;i<size-1;i++)
        {	
             if(subboard[i]>subboard[i+1])
             {
                 temp=subboard[i];
                 subboard[i]=subboard[i+1];
                 subboard[i+1]=temp;			/*swapping*/
                 swap=1;
             }
        }

        
    } while(swap);
}


/*Check if Sudoku board is valid                                                    */
/*return ILLEGAL_STATE when you have two same number in a row, or col or sub-region */
/*reutrn INCOMPLETE_STATE when the board is not completely filled with valid numbers     */
/*return GOAL_STATE if the board is solved                                          */
int CheckSudoku(int n, int *board, int indicator) {
    int i, j,a;
	int index=0;
	int p=0;
	int rowbig, colbig, col, row;
	char char1, char2;
    //copy is used as a temp array to store a row, or col, or sub-region of numbers.
    //the memory for copy is dynamically allocated
     int * copy = malloc(n*n*sizeof(int));
     int * even = malloc(n*n*sizeof(int));

	for (i=0; i<n*n; i++){
	for (j=0; j<n*n; j++){	
		copy[index]= board[p];
		++index;
		++p;							/*copying*/
	}
	    bubblesort(copy, n*n);					/*swap*/


	    for (a=0; a<n*n-1; a++){
	 	char1=copy[a]; char2= copy[a+1];
	 	if ((char1 == char2)&&(char1 !=0)){
			return ILLEGAL_STATE;}			/*check if it is illegal*/
		}
	
	index=0;
    }

/*columns*/
    index=0;
    for (col=0; col<n*n; col++){
	for (row=0; row<n*n; row++){
		p=row*(n*n)+col;
		copy[index]= board[p];
		++index;
	}
    bubblesort(copy, n*n);				/*swap*/


	    for (a=0; a<n*n-1; a++){
	 	char1=copy[a]; char2= copy[a+1];
	 	if ((char1 == char2)&&(char1 !=0)){
//		  
			return ILLEGAL_STATE;}			/*check if it is illegal*/
		}
	
    
	index=0;
    }
    
/*subregion*/
    index=0;   
    for (rowbig=0; rowbig<n; rowbig++){
	for (colbig=0; colbig<n; colbig++){
		for (row=0; row<n; row++){
			for (col=0; col<n; col++){
				p=(colbig*n+col)+(rowbig*n+row)*n*n;			
				copy[index]= board[p];
				++index;
			}
		}
	    bubblesort(copy, n*n);				/*swap*/


	    for (i=0; i<n*n-1; i++){
	 	char1=copy[i]; char2= copy[i+1];
	 	if ((char1 == char2)&&(char1 !=0)){
			return ILLEGAL_STATE;}			/*check if it is illegal*/
		}


	index=0;
  }
}

    /*check the diagonals if indicator is 1*/
if (indicator == 1){
	for (i=0; i<n*n;i++){					//left to right
		copy[i]=board[indexCal(n, i, i)]; }

	    bubblesort(copy, n*n);				/*swap*/
	    for (i=0; i<n*n-1; i++){
	 	char1=copy[i]; char2= copy[i+1];
	 	if ((char1 == char2)&&(char1 !=0)){
//		     
			return ILLEGAL_STATE;}			/*check if it is illegal*/
		}

	for (i=0; i<n*n;i++){	
		copy[i]=board[indexCal(n, i, 8-i)]; }		//right to left
	    bubblesort(copy, n*n);				/*swap*/
	    for (i=0; i<n*n-1; i++){
	 	char1=copy[i]; char2= copy[i+1];
	 	if ((char1 == char2)&&(char1 !=0)){
//			       
			return ILLEGAL_STATE;}			/*check if it is illegal*/
		}

}


    for (j=0; j<n*n*n*n; j++){ 
	char1=board[j]; 					/*if it is not illegal, is it incomplete?*/
    	if (char1 == 0){
//		
		return INCOMPLETE_STATE;}

    }
	return GOAL_STATE;   
    /*If there is no duplicates in the board, check if the board is complete*/

    /*else the board is complete and valid, thus we found the solution.*/

}



/* This function solves the board with recursion                             */
/* Base case is when you have GOAL_STATE and ILLEGAL_STATE                  */
int SolveSudoku(int n, int *board,int indicator) {
  int p, g=(n*n)+1;
	int try=0;

    	switch(CheckSudoku(n,board,indicator)) {
        	case GOAL_STATE: return 1;
        	case ILLEGAL_STATE: return 0;
    	}						/*check if solved*/

	for (p=0; p< n*n*n*n; p++)			/*if not solved, check for empty cell*/
		if (board[p]==0)
			break;				/*if it is empty, this is the cell, jump out of the loop*/
	
	try=1;						/*greatest number should be 9 if n=3*/
	while(try<g){
		board[p]=try;
;
		if(SolveSudoku(n, board, indicator)){
 // 			for (i=0;i<(n*n*n*n);i++)
     //   		printf("%d%c", board[i],((i+1)%(n*n))?' ':'\n');
    			return 1;}			/*solved*/
		try=try+1;				/*not solved, so increment*/
		board[p]=0;
	}

	board[p]=0;				/*the board is not solved, something wrong with previous cells*/
//		printf("board[%d]=%d\n", p, board[p]);
	return 0;				/*so set the cell back to 0, and return 0, try next recursion */
						/*at the upper level    */
}



#include <stdio.h>
#include "connect4.h"

/*
 * playAgain - returns 1 when the use types valid input
 * INPUTS: str - pointer to the input string
 * 	   again - pointer, contains either y or n
 * OUTPUTS: none
 * RETURN VALUE: 1 on success, 0 when the use input is not valid
 */
int playAgain(char *str, char *again)
{
	if ((str[0] == 'Y' || str[0] == 'y' || str[0] == 'N' || str[0] == 'n')
		&& str[1] == '\n')
		return 1;
	printf("Invalid input.\n");
	return 0;
}

/*
 * makeMove - modifies the board depending on the player's move
 * INPUTS: col1-7: pointers to the columns of the board
 * 	   move: the column number that the user picked
 * 	   XorO: X for player 1, O for player 2
 * OUTPUTS: col1-7: pointers to the columns of the board
 * RETURN VALUE: none
 */
void makeMove(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	      int *col7, int move, char XorO)
{
	int j;

	if (move == 1) {
		j = 6;
		while (col1[j] == 'X' || col1[j] == 'O')
			j--;
		col1[j] = XorO;
	}
	else if (move == 2) {
		j = 6;
		while (col2[j] == 'X' || col2[j] == 'O')
			j--;
		col2[j] = XorO;
	}
	else if (move == 3) {
		j = 6;
		while (col3[j] == 'X' || col3[j] == 'O')
			j--;
		col3[j] = XorO;
	}
	else if (move == 4) {
		j = 6;
		while (col4[j] == 'X' || col4[j] == 'O')
			j--;
		col4[j] = XorO;
	}
	else if (move == 5) {
		j = 6;
		while (col5[j] == 'X' || col5[j] == 'O')
			j--;
		col5[j] = XorO;
	}
	else if (move == 6) {
		j = 6;
		while (col6[j] == 'X' || col6[j] == 'O')
			j--;
		col6[j] = XorO;
	}
	else if (move == 7) {
		j = 6;
		while (col7[j] == 'X' || col7[j] == 'O')
			j--;
		col7[j] = XorO;
	}
}

/*
 * checkWin - checks if either of the players won, modifies win accordingly
 * INPUTS: col1-7 - pointers to the columns of the board
 * 	   XorO - X for player 1, O for player 2
 * OUTPUTS: win - pointer to win variable
 * RETURN VALUE: none
 */
void checkWin(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	      int *col7, int *win, char XorO)
{
	int i;

	for (i = 6; i>0; --i) { //for horizontal
		if ((col1[i] == XorO || col2[i] == XorO || col3[i] == XorO || col4[i] == XorO)
		&& (col5[i] == XorO || col2[i] == XorO || col3[i] == XorO || col4[i] == XorO)
		&& (col5[i] == XorO || col6[i] == XorO || col3[i] == XorO || col4[i] == XorO)
		&& (col5[i] == XorO || col6[i] == XorO || col7[i] == XorO || col4[i] == XorO)) {
			*win = 1;
		}
	}
	for (i = 6; i>2; --i) {
		// for vertical
		if ((col1[i] == XorO || col1[i - 1] == XorO || col1[i - 2] == XorO || col1[i - 3] == XorO)
		&& (col2[i] == XorO || col2[i - 1] == XorO || col2[i - 2] == XorO || col2[i - 3] == XorO)
		&& (col3[i] == XorO || col3[i - 1] == XorO || col3[i - 2] == XorO || col3[i - 3] == XorO)
		&& (col4[i] == XorO || col4[i - 1] == XorO || col4[i - 2] == XorO || col4[i - 3] == XorO)
		&& (col5[i] == XorO || col5[i - 1] == XorO || col5[i - 2] == XorO || col5[i - 3] == XorO)
		&& (col6[i] == XorO || col6[i - 1] == XorO || col6[i - 2] == XorO || col6[i - 3] == XorO)
		&& (col7[i] == XorO || col7[i - 1] == XorO || col7[i - 2] == XorO || col7[i - 3] == XorO)) {
			*win = 1;
		}
		// for diagonally up right
		if ((col1[i] == XorO || col2[i - 1] == XorO || col3[i - 2] == XorO || col4[i - 3] == XorO)
		&& (col2[i] == XorO || col3[i - 1] == XorO || col4[i - 2] == XorO || col5[i - 3] == XorO)
		&& (col3[i] == XorO || col4[i - 1] == XorO || col5[i - 2] == XorO || col6[i - 3] == XorO)
		&& (col4[i] == XorO || col5[i - 1] == XorO || col6[i - 2] == XorO || col7[i - 3] == XorO)) {
			*win = 1;
		}
		// for diagonally up left
		if ((col7[i] == XorO || col6[i - 1] == XorO || col5[i - 2] == XorO || col4[i - 3] == XorO)
		&& (col6[i] == XorO || col5[i - 1] == XorO || col4[i - 2] == XorO || col3[i - 3] == XorO)
		&& (col5[i] == XorO || col4[i - 1] == XorO || col3[i - 2] == XorO || col2[i - 3] == XorO)
		&& (col4[i] == XorO || col3[i - 1] == XorO || col2[i - 2] == XorO || col1[i - 3] == XorO)) {
			*win = 1;
		}
	}
}

/*
 * buildBoard - builds the board
 * INPUTS: col1-7 - pointers to the columns of the board
 * OUTPUTS: col1-7 - pointers to the columns of the board
 * RETURN VALUE: none
 */
void buildBoard(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
		int *col7)
{
	int i;

	for (i = 0; i<7; i++) {
		if (i == 0)
			printf("\n\n\n   %d %d %d %d %d %d %d  \n  ---------------\n",
			col1[i], col2[i], col3[i], col4[i], col5[i], col6[i], col7[i]);
		if (i>0 && i<7)
			printf(" | %c %c %c %c %c %c %c |\n",
			col1[i], col2[i], col3[i], col4[i], col5[i], col6[i], col7[i]);
		if (i == 6);
			printf("  ---------------\n\n");
	}
}

/*
 * getMove - gets the move from the player, puts it to move
 * INPUTS: col1-7 - pointers to the columns of the board
 * 	   playernum - player number, 1 or 2
 * OUTPUTS: move - pointer to the move variable
 * RETURN VALUE: 1 on success, 0 otherwise
 */
int getMove(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	     int *col7, int *move, int playernum)
{
	char buf[200];

	do {
		printf("Player %d: ", playernum);
		if (NULL == fgets(buf, 200, stdin)) {
			printf("\nProgram terminated.\n");
			return 0;
		}
	} while (!checkMove(col1, col2, col3, col4, col5, col6, col7, buf, move));
	printf("\n\n");
	return 1;
}

/*
 * checkMove - checks whether the move is valid
 * INPUTS: col1-7 - pointers to the columns of the board
 * 	   str - input string from the user
 * OUTPUTS: move - pointer to the move variable
 * RETURN VALUE: 1 on success, 0 otherwise
 */
int checkMove(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	      int *col7, char *str, int *move)
{
	if ((1 == sscanf(str, "%d", move)) && (*move>0) && (*move<8)) {
		if ((*move == 1 && (col1[1] == 'X' || col1[1] == 'O'))
			|| (*move == 2 && (col2[1] == 'X' || col2[1] == 'O'))
			|| (*move == 3 && (col3[1] == 'X' || col3[1] == 'O'))
			|| (*move == 4 && (col4[1] == 'X' || col4[1] == 'O'))
			|| (*move == 5 && (col5[1] == 'X' || col5[1] == 'O'))
			|| (*move == 6 && (col6[1] == 'X' || col6[1] == 'O'))
			|| (*move == 7 && (col7[1] == 'X' || col7[1] == 'O'))) {
			printf("Can't let you move there!\n\n");
			return 0;
		}
		else {
			return 1;
		}
	}
	printf("Invalid input.\n\n");
	return 0;
}

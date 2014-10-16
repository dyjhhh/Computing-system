#include <stdio.h>
#include "connect4.h"
 
 
int main()
{
	int col1[7]={1,'*','*','*','*','*','*'};	// Initialize the board.
	int col2[7]={2,'*','*','*','*','*','*'};
	int col3[7]={3,'*','*','*','*','*','*'};
	int col4[7]={4,'*','*','*','*','*','*'};
	int col5[7]={5,'*','*','*','*','*','*'};
	int col6[7]={6,'*','*','*','*','*','*'};
	int col7[7]={7,'*','*','*','*','*','*'};

	int move, win=0, i;
	char again = 'y', buf[200];

	while(again=='Y'||again=='y') {		// Play while the player says yes.
		buildBoard(col1, col2, col3, col4, col5, col6, col7);
		while(win==0) {
			// If nobody's winning, get move from player 1. Same for player 2.
			if(win==0) {
				if(0 == getMove(col1, col2, col3, col4, col5, col6, col7, &move, 1))
					return 3;
				makeMove(col1, col2, col3, col4, col5, col6, col7, move, 'X');
			}
			buildBoard(col1, col2, col3, col4, col5, col6, col7);
			checkWin(col1, col2, col3, col4, col5, col6, col7, &win, 'X');
			// Check for win for every iteration, for both players.

			if(win==0) {
				if(0 == getMove(col1, col2, col3, col4, col5, col6, col7, &move, 2))
					return 3;
				makeMove(col1, col2, col3, col4, col5, col6, col7, move, 'O');
			}

			buildBoard(col1, col2, col3, col4, col5, col6, col7);
			checkWin(col1, col2, col3, col4, col5, col6, col7, &win, 'O');
		}

		printf("Player %d Wins!!!\n\n", win);

		do {
			printf("Would you like to play again? (Y/N): ");
			if (NULL == fgets(buf, 200, stdin)) {
				printf("\nProgram terminated.\n");
				return 3;
			}
		} while (!playAgain(buf,&again));

		printf("\n\n\n\n\n\n");
		win=0;
		for(i=1;i<7;i++) {	// Reset the board for the next game.
			col1[i]='*';
			col2[i]='*';
			col3[i]='*';
			col4[i]='*';
			col5[i]='*';
			col6[i]='*';
			col7[i]='*';
		}
	}

	printf("Thanks for playing!\n\n");
	return 0;
}

int playAgain(char *str, char *again);

void makeMove(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	      int *col7, int move, char XorO);

void checkWin(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	      int *col7, int *win, char XorO);

void buildBoard(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
		int *col7);

int getMove(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	     int *col7, int *move, int playernum);

int checkMove(int *col1, int *col2, int *col3, int *col4, int *col5, int *col6,
	      int *col7, char *str, int *move);

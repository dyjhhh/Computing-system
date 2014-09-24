#include <stdio.h>

#include "codebreaker.h"

int main ()
{
    char buf[200];
    int turn;
    int peg[4];
    int guess[4];

    do {
	printf ("Please enter a seed: ");
	if (NULL == fgets (buf, 200, stdin)) {
	    printf ("\nProgram terminated.\n");
	    return 3;
	}
    } while (!set_seed (buf));

    if (!start_game (&peg[0], &peg[1], &peg[2], &peg[3])) {
        printf ("\nGame start failed.\n");
	return 3;
    }

    for (turn = 1; 10 >= turn; turn++) {
	printf ("Guess %d\n", turn);
	do {
	    printf ("Enter your guess (#1 #2 #3 #4): ");
	    if (NULL == fgets (buf, 200, stdin)) {
		printf ("\nProgram terminated.\n");
		return 3;
	    }
	} while (!make_guess (buf, &guess[0], &guess[1], &guess[2], &guess[3]));
	if (guess[0] == peg[0] && guess[1] == peg[1] && guess[2] == peg[2] &&
	    guess[3] == peg[3]) {
	    printf ("You guessed correctly in %d guesses.\n", turn);
	    return 0;
	}
    }
    puts ("You failed to guess correctly in 10 guesses.\n");
    printf ("The solution was %d %d %d %d.\n", peg[0], peg[1], peg[2], peg[3]);

    return 0;
}


/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * here to help you get started.
 */

#include <stdio.h>
#include <stdlib.h>

#include "codebreaker.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables.  You may need others for solving the challenges.  A
 * sample for one variable of the code is shown below for you.
 */

static int peg1;
static int peg2;
static int peg3;
static int peg4;
static int turn;
static int guess1;
static int guess2;
static int guess3;
static int guess4;


/*
 * set_seed -- uses sscanf to find the random seed value, then initializes
 *             the random number generator by calling srand with the seed
 * INPUTS: seed_str -- a string entered by the user for the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (contains something
 *               other than a single integer), or 1 on success
 * SIDE EFFECTS: initializes pseudo-random number generation
 */
int set_seed(const char* seed_str){
	int seed;
	char post[2];
	if (1 == sscanf(seed_str, "%d%1s", &seed, post)){
		srand(seed);
		return 1;
	}
	printf("set_seed: invalid seed. \n");
	return 0;
}



/*
 * start_game -- creates the solution combination using the approach
 *               described in the assignment specification (using rand)
 * INPUTS: none
 * OUTPUTS: *one -- the first color value in the code (between 1 and 8)
 *          *two -- the second color value in the code (between 1 and 8)
 *          *three -- the third color value in the code (between 1 and 8)
 *          *four -- the fourth color value in the code (between 1 and 8)
 * RETURN VALUE: 1 on success, or 0 on failure (should never fail, though)
 * SIDE EFFECTS: records the solution code for use by make_guess
 */
int start_game(int* one, int* two, int* three, int* four)
{
	// REPLACE THIS WITH YOUR OWN CODE

	*one = 1 + rand() % 8;
	*two = 1 + rand() % 8;
	*three = 1 + rand() % 8;
	*four = 1 + rand() % 8;

	peg1 = *one;
	peg2 = *two;
	peg3 = *three;
	peg4 = *four;

	return 1;
}


/*
 * make_guess -- calculates the number of perfect, high, and low matches
 *               for a given guess, relative to the solution code recorded
 *               earlier by start_game
 * INPUTS: guess_str -- a string consisting of four numbers for the guess
 * OUTPUTS: the following are only valid if the function returns 1
 *          *one -- the first color value in the guessed code (between 1 and 8)
 *          *two -- the second color value in the guessed code (between 1 and 8)
 *          *three -- the third color value in the guessed code
 *                    (between 1 and 8)
 *          *four -- the fourth color value in the guessed code
 *                    (between 1 and 8)
 * RETURN VALUE: 1 if the guess string is valid (represents exactly four
 *               numbers between 1 and 8), or if 0 it is not
 * SIDE EFFECTS: prints the number of matches found using printf
 *               (NOTE: the output format MUST MATCH EXACTLY)
 */
int make_guess(const char* guess_str, int* one, int* two,
	int* three, int* four)
{
	// REPLACE THIS WITH YOUR OWN CODE
	char guess;
	if (4 == sscanf(guess_str, "%d %d %d %d", &guess1, &guess2, &guess3, &guess4)){
		int perfect = 0;
		int high = 0;
		int low = 0;

		int guessNum[4];
		int pegNum[4];

		guessNum[0] = guess1;
		guessNum[1] = guess2;
		guessNum[2] = guess3;
		guessNum[3] = guess4;

		int i, j;

		pegNum[0] = peg1;
		pegNum[1] = peg2;
		pegNum[2] = peg3;
		pegNum[3] = peg4;

		//First count the perefect match
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){

				if (guessNum[i] == pegNum[j]){
					perfect++;
					guessNum[i] = -1;
					pegNum[j] = -1;


				}
			}
		}

		//Count high and low.
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				if (pegNum[i] > 0 && guessNum[j] >0){
					if (guessNum[i] < pegNum[j]){
						high++;
						guessNum[i] = -1;
						pegNum[j] = -1;
						break;
					}
					else{
						low++;
						guessNum[i] = -1;
						pegNum[j] = -1;

						break;
					}
				}
			}
		}

		turn++;
		printf("With guess %d, you got %d perfect match, %d high and %d low.\n", turn, perfect, low, high);


		*one = guess1;
		*two = guess2;
		*three = guess3;
		*four = guess4;
		return 1;
	}

	else {
		printf("set_seed: invalid seed. \n");
		return 0;


	}

}



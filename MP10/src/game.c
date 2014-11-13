/*! Game module

    Implements the snake game, which consists of snake head and tail movement and
    random addition of food to the board by providing a function (next_frame) that
    performs one snake game iteration.
    Also provides functions for creating, destroying, and accessing game elements.
*/

#include "game.h"

#include <stdlib.h>

cell * board_cell(board * cur_board, int row, int col)
/*! Given a board, a row, and a column, return a pointer to the corresponding
    cell on the board. (See game.h for board data structure specification)
    This function should be handy for accessing board cells.
*/
{
    
}

void randomly_add_food(board * cur_board, float probability)
/*! Given a board and a probability, perform a random binary test
    that passes with the given probability (the random function will
    be useful for this, see "random" man page).  If the test passes, select
    a random cell on the board (each cell should have an equal chance
    of being selected) and change that cell to food if it is currently
    an open cell.  If the selected cell is not open, do nothing.

    We recommend that the default seed be used with the random number
    library, in order to produce deterministic results that make bugs
    easier to track down.  (i.e. just use random without calling srandom)
*/
{

   
    
}

board * create_board(int rows, int cols)
/*! Create an instance of a board structure with the given number of rows
    and columns, initializing elements to open cells and return a pointer
    to it. (See game.h for the specification for the board data structure) 
    The needed memory should be dynamically allocated with the malloc family
    of functions.

    Note that the calloc function is useful for allocating and zeroing
    memory in one call (see "calloc" man page)
*/
{
   
}

void destroy_board(board * cur_board)
/*! Free memory allocated by create_board to create the given board instance. */
{
    
    
}

snake * create_snake(board * cur_board, int row, int col, direction heading, int initial_growth)
/*! Create a single-segment snake (See game.h for data structure specification)
    at the given row and column, with the given heading and given growth.
    Needed memory should be dynamically allocated with the malloc family of
    functions.  Mark the corresponding cell on the given board as occupied by
    a snake, and return a pointer to the newly created snake instance */
{
    /* This code is complete. You need not modify it.*/
    snake_segment * segment = malloc(sizeof(snake_segment));
    segment->row = row;
    segment->col = col;
    segment->next = NULL;

    snake * new_snake = malloc(sizeof(snake));
    new_snake->head = segment;
    new_snake->tail = segment;
    new_snake->heading = heading;
    new_snake->growth = initial_growth;
    new_snake->food = 0;
    new_snake->length = 1;

    *board_cell(cur_board, row, col) = CELL_SNAKE;
    return new_snake;
}

void destroy_snake(snake * cur_snake)
/*! Free memory associated with the given snake instance. */
{
    
}

void append_snake_head(snake * cur_snake, board * cur_board, int row, int col)
/*! Add a new snake segment to the given snake with the given row and column.
    This segment is the new snake head; update the snake data structure to integrate
    the new segment.  Needed memory should be allocated with the malloc family of
    functions.  Also mark the corresponding cell on the given board as being occupied
    by a snake.
*/
{
   
}

void remove_snake_tail(snake * cur_snake, board * cur_board)
/*! Mark the cell on the board corresponding to the snake's last segment
    as open and remove the last segment from the snake.  Update the snake
    data structure to reflect this removal.
    
    If this removal results in the snake having no segments, then set the
    snake's tail and head to NULL to indicate a nonexistent snake.
*/
{
    
    
}

void update_snake_head(snake * cur_snake, board * cur_board, int growth_per_food)
/*! Attempt to move the head of the given snake one cell (by appending to the snake)
    according to the snake's heading (north is up).  The head can move in the given
    direction if the destination cell is either open or food.  If the cell is food,
    add the given growth per food to the snake's growth counter.  If the destination
    cell is a snake or wall, do nothing.
*/
{   
    
}

void update_snake_tail(snake * cur_snake, board * cur_board)
/*! If the given snake's growth counter is 0, advance the tail of the
    given snake one cell (by removing the current snake tail).
    If the snake's growth counter is positive, decrement the growth
    counter and do not move the snake's tail.
*/
{
 
}

int next_frame(game * cur_game)
/*! Modify the state of the given snake game to reflect one game iteration.
    This consists of moving human and computer snakes and randomly adding food to the board.
*/
{
  /* This code is complete; you should not need to modify it */
    /* The computer snake gets priority (House always wins ties) */
    update_snake_head(cur_game->computer_snake, cur_game->board, cur_game->growth_per_food);
    update_snake_head(cur_game->human_snake, cur_game->board, cur_game->growth_per_food);
    update_snake_tail(cur_game->computer_snake, cur_game->board);
    update_snake_tail(cur_game->human_snake, cur_game->board);
    randomly_add_food(cur_game->board, cur_game->food_probability);
    return 0;  
}

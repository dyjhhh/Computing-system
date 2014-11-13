/*! AI module

    Implements the Artifical Intelligence of the computer controlled snake by
    providing a function that determines the computer's next move based on the
    current game state.
    
    The AI's goal is simply to find the shortest path to the nearest food, and to
    then follow that path.  If food is inaccessible, then the AI's goal is to avoid
    hitting walls.
*/

#include "ai.h"

#include <limits.h>
#include <stdlib.h>

void find_food(board * cur_board, int * distance_map, int row, int col,
               int distance, int * closest_distance)
/*! Given a board (data structure specified in game.h), a starting row and column,
    and a given path distance traveled, recursively search the board to find the
    shortest path to food.  The closest_distance input/output parameter indicates
    the closest distance to food found thus far.  When closer food is found, update
    closest_distance to reflect that.

    The distance map parameter is an array of integers corresponding to the board
    cell array.  In order for the search of large boards to finish in a reasonable
    amount of time, each entry in the distance map should be updated with the shortest
    path distance found to the corresponding cell thus far and a branch of the search
    should be ignored if it finds a path to a cell that is as long or longer than the
    shortest distance recorded in the distance map for that cell. (because that
    search is going to produce the same or worse results)
*/
{   
   
}

int food_distance(board * cur_board, int * distance_map, int row, int col)
/*! Given a board (data structure defined in game.h), a distance map (format defined
    in find_food) which is only allocated, not initialized, and a starting row and
    column, return the closest path distance to food.
    If no food is found, return INT_MAX (defined in limits.h,
    see http://uw714doc.sco.com/en/man/html.4/limits.4.html )
*/
{
   
}

void avoid_walls(board * cur_board, snake * cur_snake)
/*! Given a board and a snake (see game.h for data structure definitions)
    modify the heading of the given snake to avoid crashing into walls or
    snakes, if possible.
    This function assumes that no food is in reach of the given snake.
*/
{
    
}

void ai_move(game * cur_game)
/*! Given a game state (game data structure defined in game.h), determine the
    computer's next move.  For each cell adjacent to the snake head, search for
    food.  If food is found, change the computer snake's heading to go to the cell
    that has the closest distance to food. (If two or more cells have the shortest
    distance, then you are free to choose one of them)

    If no food is found, then simply call the avoid_walls function.
*/
{
   
    
}




/*! File module

    Provides level loading functionality through a function that creates a game from a
    level file.  Also provides a function for destroying the game instance for use during
    teardown.
*/

#include "game.h"
#include "file.h"

#include <stdio.h>
#include <stdlib.h>

game * create_game(const char * file_name)
/*! Load an input level file with given file_name with format specified in levels/README.txt,
    and transform the serialized data within into a game data structure, specified in game.h
    Return a pointer to the game instance on success, NULL on failure.

    Note that error handling is not required for credit, but may help with testing.

    The game and structures it points to should be allocated with the malloc family of
    functions.  Make sure to take advantage of allocation functions provided by the game module.
*/
{

}

void destroy_game(game * cur_game)
/*! Deallocate any memory acquired with malloc associated with the given game instance.
    This includes any substructures the game data structure contains.  Make sure to take
    advantage of deallocation functions provided by the game module. */
{
    
}

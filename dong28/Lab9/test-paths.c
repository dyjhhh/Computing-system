#include <stdio.h>
#include "paths.h"

int main()
{
    printf("Testing (1,0) -> (4,1) (4 paths)\n");
    printf("Result: %d\n", count_shortest_paths(1, 0, 4, 1));
    //add more test cases to test your function

    return 0;
}

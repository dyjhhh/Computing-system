#include <stdio.h>
#include <stdlib.h>
#include "mp12.h"

#define POSTFIX 0
#define INFIX   1

int main(int argc, char *argv[])
{
	if (argc < 2) 
	{
		printf("Not enough arguments provided.\n");
		return -1;
	}
    char buf[100];
	int notation_type = atoi(argv[1]);
    if (notation_type == POSTFIX)
    {
        printf("Please enter a postfix expression: ");
        scanf("%[^\n]", buf);
    	postfix(buf);
    }
    else if (notation_type == INFIX)
    {
        printf("Please enter an infix expression: ");
        scanf("%[^\n]", buf);
    	infix(buf);
    }
    else
    {
    	printf("Invalid notation type\n");
    	return -1;
    }

    return 0;
}

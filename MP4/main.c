#include <stdio.h>
#include "printBinary.h"

// FUNCTION DECLARATIONS
void convert(int value, int key);

int main(void)
{
    int value, key;
    char inCheck;

    // Get integer and check for valid
    printf("Enter an integer: ");
    if (scanf("%d%c", &value, &inCheck) != 2 || inCheck != '\n')
    {
        printf("Invalid input\n");
        return -1;
    }

    // Get conversion key
    printf("0: Binary\n1: Octal\n2: Decimal\n3: Hex\n");
    printf("Enter conversion: ");
    scanf("%d", &key);

    // Convert base and print
    convert(value, key);
    return 0;
}

/*
 * Converts a value to a different base representation and prints it
 * @param value The value to convert
 * @param key The key that indicates the conversion operation
 * @return none
 */
void convert(int value, int key)
{
    // YOUR CODE GOES HERE.
}


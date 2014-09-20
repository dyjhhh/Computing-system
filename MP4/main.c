#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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
//start conversion
void convert(int value, int key)
{
switch (key)
{
//if 0 is entered, convert to binary
 case 0:
 {
 void printBinary(const unsigned char val);;
 }
//if 1 is entered, convert to octal
 case 1:
 printf("%o\n", value);
 break;
//if 2 is entered, convert to decimal
 case 2:   
   printf("%d\n", value);
 break;
//if 3 is entered, convert to hex
 case 3:
   printf("%x\n", value);
   break;
//if no choice is matched, print out error message
 default:
   printf("Invalid option\n");
   }
}

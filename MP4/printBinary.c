#include <stdio.h>
#include "printBinary.h"

void printBinary(int value, int size) {
    for(int i = 31; i >= 0; i--) {
     size = value >> i;
        if (size & 1) {
            printf ("1");
        } else {
            printf("0");
        }
    }
}
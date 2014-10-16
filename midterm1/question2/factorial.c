#include <stdio.h>

 

int main(void)

{

    int n; /* calculate from 1! to n! */


    /* Read n */

    printf("Enter n: ");

    scanf("%d", &n);

     

    if ((n < 1) || (n > 12)) {

       printf("Number out of range.\n");

       return -1;

    }

 
    /* Calculate 1! to n! Insert your code here */
    int m;
    int f;
    while (m<(n-1)){
      f=m;
      m++;
      printf("%d*", m);
     f=m*(m-1); 
    }
    printf ("%d", n);
    printf("=%d", f);
    return 0;
}


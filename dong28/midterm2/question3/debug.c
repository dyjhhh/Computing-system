#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateCopy(char s[], char new[])
{
  int i;
    int len = strlen(s);

    for (i = 0; i < len; ++i){
      new[i] = s[i];
       new[len+i] = s[i];
       if ( s[i] == '/0'){
	 break;
       }
}
}

int main () 
{
    char buffer[10];
    char buffer2[20];

    printf("Enter a string of 10 or fewer characters\n");
    scanf("%s", buffer);

    CreateCopy(buffer, buffer2); 

    printf("%s\n", buffer2);
    return 0;
}

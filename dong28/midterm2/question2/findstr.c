#include <stdio.h>
#include <string.h>

int findSubStr(char str[], char substr[]);

// You do not have to modify or even really understand the main function.
// Only edit findSubStr function below.
int main()
{
	char str[200], substr[200];
	int length;

	printf("Enter the main string: ");
	if (NULL == fgets(str, 200, stdin)) {	// Get the input string from the user.
		printf("Program terminated.\n");
		return 3;
	}
	length = strlen(str) - 1;	// Replace the newline char at the end by a null char
	if (str[length] == '\n')	// for the purposes of this problem.
		str[length] = '\0';
	if (length == 0) {
		printf("No main string entered.\n");
		return 3;
	}
	printf("Enter the substring: ");
	if (NULL == fgets(substr, 200, stdin)) {
		printf("Program terminated.\n");
		return 3;
	}
	length = strlen(substr) - 1;
	if (substr[length] == '\n')
		substr[length] = '\0';
	if(length == 0) {
		printf("No substring entered.\n");
		return 3;
	}

	if (findSubStr(str, substr) == 1)
		printf("Substring found!\n");
	else
		printf("No substring found in the main string.\n");
	return 0;
}

/*
 * findSubStr - looks for substr inside str
 * INPUTS: str - the main string
 * 	   substr - the substring to look for inside str
 * OUTPUT: none
 * RETURN VALUE: 1 on success, 0 otherwise
 */
int findSubStr(char str[], char substr[])
{
  int i;
  int j;
  for (i=0;;++i){
    for (j=0;;++j){
      if (str[j] == substr[i]){
	return 1;
      }
	else{
	  return 0;
	}
      }
    }// Write your code here!
}

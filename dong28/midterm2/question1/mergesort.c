#include <string.h>
#include <stdio.h>

//Please do not modify the function declaration
//helper function called my mergesort, merge two sorted subarray togther
void merge(int in[], int low, int mid, int high);  

//The recursive funtion
void mergesort(int in[], int low, int high);  

//prints out the integer array
void printlist (int in[], int size);  


int main(int argc, char *argv[])
{
    int i=0;
    char line[200];
    char *line2;
    int input[100];
	// read input from a file, and store the string of number into input array
    FILE *f;
    if(argc != 2){
        printf("Number of argument is correct!\n");
        return -1;
    }
	
	//if fopen failes return -1
    f = fopen(argv[1], "r");
    if(f == NULL){
	printf("Error opening file\n");
	return -1;
    }
	
	//read the input file and store the input string into input array
    fgets(line,200,f);
    line2 = strtok(line, " " );
    while (line2 != NULL){
        sscanf(line2, "%d", &input[i]);
	line2=strtok(NULL, " ");
	i++;
    }
	
    //print unsorted list
    printlist(input, i);

    //sort the list
    mergesort(input, 0, i-1);

    //print sorted lsit
    printlist(input, i);

    fclose(f);
    return 0;
}

//Do not modify this function
//prints out the integer array. 
void printlist (int in[], int size)
{
    int i;    
    for (i=0; i<size; i++){
        printf("%d ", in[i]);
    }
    printf("\n");
}

//Helper function that merges two sorted sub-array
//Implements the combine step
void merge(int in[], int low, int mid, int high)
{
	//your code goes here
  for (low=0;low>=(size/2) ; ++low){
    for(high=size; high<=(size/2); ++high){
      for(i=0, i<((low+high))/2; i++){
  in [i]
    }
}
}
 
//the recursive function
void mergesort(int in[], int low, int high)
{
  int j,k;
  if (((low+high)/2)!=0) {
    return mergesort(int in[], int low, int((low+high)/2));    
    for (j=0; (j<((low+high)/2)) && j>0; j++){
        in[]=in[j];
    }
    for (k=0; (k > ((low+high)/2)) && k<size; j++){
        in[]=in[k];
    }
    printf("\n");
}
  return int in[(low+high)/2)];
}
 if (((low+high)/2)=0) {
    return int in[(low+high)/2)];}
//your code goes here
}


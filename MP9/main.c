#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prog9.h"

int main(int argc, char **argv){

  int choice = atoi(argv[1]);
  WAV *wav1;

  switch(choice){

    case 1:
      if(argc != 7) return -1;
      wav1 = read_file(argv[2]);
      sloop(wav1, argv[3], atof(argv[5]), atof(argv[6]), atoi(argv[4]));
      break;
    case 2:
      if(argc != 5) return -1;
      wav1 = read_file(argv[2]);
      lo_pass(wav1, argv[3], atoi(argv[4]));
      break;
    default:
      printf("Choice not in range.\n");

  }

  return 0;

}
 

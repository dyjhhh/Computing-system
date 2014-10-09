#include "imageData.h"
#include "functions.h"

const double gMonoMult[3]={.299,.587,.144};

int main(int argc,char *argv[])
{
  //Handles user input
  if(argc<4 || argc>5)
  {
    printf("Incorrect number of arguments\n");
    printf("Number of arguments: %d\n",argc);
    exit(1);
  }

  //const char *inputFilename=argv[1];
  const char *inputFilename=argv[1];
  printf("Inputfile: %s\n",inputFilename);
  const char *outputFilename=argv[2];
  char garbage[2];
  int command;
  double sigma=3;

  if(1!=sscanf(argv[3],"%d%1s",&command,garbage) || command<0 || command>11)
  {
    printf("Incorrect command\n");
    exit(1);
  }

  if(command>0 && command<11 && argc==5)
  {
    printf("Incorrect number of arguments, exclude the sigma value");
    exit(1);
  }

  if(((command==0 || command==11) && argc==5 && 1!=sscanf(argv[4],"%lf%1s",&sigma,garbage)) || sigma<0)
  {
    printf("Incorrect sigma value\n");
    exit(1);
  }

  Filter *filters=initializeFilters(sigma);
  Image *inputImage=decode(inputFilename);
  printf("Width: %d, height: %d\n",inputImage->width,inputImage->height);
  Image *outputImage=generateOutput(inputImage);

  uint8_t *inRed=inputImage->redChannel;
  uint8_t *inBlue=inputImage->blueChannel;
  uint8_t *inGreen=inputImage->greenChannel;
  uint8_t *inAlpha=inputImage->alphaChannel;
  uint8_t *outRed=outputImage->redChannel;
  uint8_t *outBlue=outputImage->blueChannel;
  uint8_t *outGreen=outputImage->greenChannel;
  uint8_t *outAlpha=outputImage->alphaChannel;
  int height=inputImage->height;
  int width=inputImage->width;
  switch(command)
  {
    case(0):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[0].filter,filters[0].radius,width,height);
      break;
    }
    case(1):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[1].filter,filters[1].radius,width,height);
      break;
    }
    case(2):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[2].filter,filters[2].radius,width,height);
      break;
    }
    case(3):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[3].filter,filters[3].radius,width,height);
      break;
    }
    case(4):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[4].filter,filters[4].radius,width,height);
      break;
    }
    case(5):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[5].filter,filters[5].radius,width,height);
      break;
    }
    case(6):
    {
      convolveImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,filters[6].filter,filters[6].radius,width,height);
      break;
    }
    case(7):
    {
      convertToGray(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                    outAlpha,gMonoMult,width,height);
      break;
     }
    case(8):
    {
      invertImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                  outAlpha,width,height);
      break;
    }
    case(9):
    {
      flipImage(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
                outAlpha,width,height);
      break;
    }
    case(10):
    {
      pixelate(inRed,inBlue,inGreen,inAlpha,outRed,outBlue,outGreen,
               outAlpha,8,8,width,height);
      break;
    }
    case(11):
    {
      Image *invImage=generateOutput(inputImage);
      Image *blurImage=generateOutput(inputImage);
      pencilSketch(inRed,inBlue,inGreen,inAlpha,invImage->redChannel,
                   invImage->blueChannel,invImage->greenChannel,
                   invImage->alphaChannel,blurImage->redChannel,
                   blurImage->blueChannel,blurImage->greenChannel,
                   blurImage->alphaChannel,outRed,outBlue,outGreen,
                   outAlpha,filters[0].filter,filters[0].radius,width,height,
                   gMonoMult);
      //NOTE THAT I NEED TO FREE EACH OF THE CHANNEL INDIVIDUALLY
      //MAKE A FREE IMAGE FUNCTION
      freeImage(invImage);
      freeImage(blurImage);
      break;
    }
    default:
      exit(1);
  }

  if(command!=12)
    encode(outputFilename,outputImage);

  free((double*)filters[0].filter);
  free(filters);
  freeImage(inputImage);
  freeImage(outputImage);
  return 0;
}

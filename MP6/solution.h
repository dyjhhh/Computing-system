#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

int getRadiusSol(double sigma);
void calculateGausFilterSol(double *gausFilter,double sigma);
void convolveImageSol(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
                   uint8_t *inAlpha,uint8_t *outRed,uint8_t *outBlue,
                   uint8_t* outGreen,uint8_t* outAlpha,const double *filter,
                   int radius,int width,int height);
void convertToGraySol(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
                   uint8_t *inAlpha,uint8_t *outRed,uint8_t *outBlue,
                   uint8_t *outGreen,uint8_t *outAlpha,const double *gMonoMult,
                   int width,int height);
void invertImageSol(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,uint8_t *inAlpha,
                  uint8_t *outRed,uint8_t *outBlue,uint8_t *outGreen,uint8_t *outAlpha,
                  int width,int height);
void flipImageSol(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,uint8_t *inAlpha,
               uint8_t *outRed,uint8_t *outBlue,uint8_t *outGreen,uint8_t *outAlpha,
               int width,int height);
void pixelateSol(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,uint8_t *inAlpha,
              uint8_t *outRed,uint8_t *outBlue,uint8_t *outGreen,uint8_t *outAlpha,
              int pixelY,int pixelX,int width,int height);
void colorDodgeSol(uint8_t *aRed,uint8_t *aBlue,uint8_t *aGreen,uint8_t *aAlpha,
                 uint8_t *bRed,uint8_t *bBlue,uint8_t *bGreen,uint8_t *bAlpha,
                 uint8_t *outRed,uint8_t *outBlue,uint8_t *outGreen,uint8_t *outAlpha,
                 int width,int height);
void pencilSketchSol(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,uint8_t *inAlpha,
                  uint8_t *invRed,uint8_t *invBlue,uint8_t *invGreen,uint8_t *invAlpha,
                  uint8_t *blurRed,uint8_t *blurBlue,uint8_t *blurGreen,uint8_t *blurAlpha,
                  uint8_t *outRed,uint8_t *outBlue,uint8_t *outGreen,uint8_t *outAlpha,
                  const double *filter,int radius,int width,int height,const double *gMonoMult);

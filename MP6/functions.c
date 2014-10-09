#include "functions.h"

/*
 * getRadius - returns the radius based on the sigma value
 * INPUTS: sigma - sigma in the Guassian distribution
 * OUTPUTS: none
 * RETURN VALUE: radius - radius of the filter
 */
int getRadius(double sigma)
{
  return 0;
}

/*
 * calculateGausFilter - calculates the Gaussian filter
 * INTPUTS: gausFitler - pointer to the array for the gaussian filter
 *          sigma - the sigma in the Gaussian distribution
 * OUTPUTS: none
 * RETURN VALUE: none
 */
void calculateGausFilter(double *gausFilter,double sigma)
{
  return;
}

/* convolveImage - performs a convolution between a filter and image
 * INPUTS: inRed - pointer to the input red channel
 *         inBlue - pointer to the input blue channel
 *         inGreen - pointer to the input green channel
 *         inAlpha - pointer to the input alpha channel
 *         filter - pointer to the convolution filter
 *         radius - radius of the convolution filter
 *         width - width of the input image
 *         height - height of the input image
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void convolveImage(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
                   uint8_t *inAlpha, uint8_t *outRed,uint8_t *outBlue,
                   uint8_t *outGreen,uint8_t *outAlpha,const double *filter,
                   int radius,int width,int height)
{
  return;
}

/* convertToGray - convert the input image to grayscale
 * INPUTS: inRed - pointer to the input red channel
 *         inBlue - pointer to the input blue channel
 *         inGreen - pointer to the input green channel
 *         inAlpha - pointer to the input alpha channel
 *         gMonoMult - pointer to array with constants to be multipiled 
 *                     with RBG channels to convert image to grayscale
 *         width - width of the input image
 *         height - height of the input image
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void convertToGray(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
                   uint8_t *inAlpha,uint8_t *outRed,uint8_t *outBlue,
                   uint8_t *outGreen,uint8_t *outAlpha,
                   const double *gMonoMult,int height,int width)
{
  return;
}

/* flipImage - flips the image in both the horizontal and vertical directions
 * INPUTS: inRed - pointer to the input red channel
 *         inBlue - pointer to the input blue channel
 *         inGreen - pointer to the input green channel
 *         inAlpha - pointer to the input alpha channel
 *         width - width of the input image
 *         height - height of the input image
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void flipImage(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
               uint8_t *inAlpha,uint8_t *outRed,uint8_t *outBlue,
               uint8_t *outGreen,uint8_t *outAlpha,int height,int width)
{
  return;
}

/* invertImage - inverts the colors of the image
 * INPUTS: inRed - pointer to the input red channel
 *         inBlue - pointer to the input blue channel
 *         inGreen - pointer to the input green channel
 *         inAlpha - pointer to the input alpha channel
 *         width - width of the input image
 *         height - height of the input image
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void invertImage(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
                 uint8_t *inAlpha,uint8_t *outRed,uint8_t *outBlue,
                 uint8_t *outGreen,uint8_t *outAlpha,int height,int width)
{
  return;
}

/* pixelate - pixelates the image
 * INPUTS: inRed - pointer to the input red channel
 *         inBlue - pointer to the input blue channel
 *         inGreen - pointer to the input green channel
 *         inAlpha - pointer to the input alpha channel
 *         pixelateY - height of the block
 *         pixelateX - width of the block
 *         width - width of the input image
 *         height - height of the input image
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void pixelate(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
              uint8_t *inAlpha,uint8_t *outRed,uint8_t *outBlue,
              uint8_t *outGreen,uint8_t *outAlpha,int pixelY,int pixelX,
              int width,int height)
{
  return;
}

/* colorDodge - blends the bottom layer with the top layer
 * INPUTS: botRed - pointer to the bottom red channel
 *         botBlue - pointer to the bottom blue channel
 *         botGreen - pointer to the bottom green channel
 *         botAlpha - pointer to the bottom alpha channel
 *         topRed - pointer to the top red channel
 *         topBlue - pointer to the top blue channel
 *         topGreen - pointer to the top green channel
 *         topAlpha - pointer to the top alpha channel
 *         width - width of the input image
 *         height - height of the input image
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void colorDodge(uint8_t *botRed,uint8_t *botBlue,uint8_t *botGreen,
                uint8_t *botAlpha,uint8_t *topRed,uint8_t *topBlue,
                uint8_t *topGreen,uint8_t *topAlpha,uint8_t *outRed,
                uint8_t *outBlue,uint8_t *outGreen,uint8_t *outAlpha,
                int width,int height)
{
  return;
}

/* pencilSketch - creates a pencil sketch of the input image
 * INPUTS: inRed - pointer to the input red channel
 *         inBlue - pointer to the input blue channel
 *         inGreen - pointer to the input green channel
 *         inAlpha - pointer to the input alpha channel
 *         invRed - pointer to temporary red channel for inversion
 *         invBlue - pointer to temporary blue channel for inversion
 *         invGreen - pointer to temporary green channel for inversion
 *         invAlpha - pointer to temporary alpha channel for inversion
 *         blurRed - pointer to temporary red channel for blurring
 *         blurBlue - pointer to temporary blue channel for blurring
 *         blurGreen - pointer to temporary green channel for blurring
 *         blurAlpha - pointer to temporary alpha channel for blurring
 *         filter - pointer to the gaussian filter to blur the image
 *         radius - radius of the gaussian filter
 *         width - width of the input image
 *         height - height of the input image
 *         gMonoMult - pointer to array with constants to be multipiled with 
 *                     RBG channels to convert image to grayscale
 * OUTPUTS: outRed - pointer to the output red channel
 *          outBlue - pointer to the output blue channel
 *          outGreen - pointer to the output green channel
 *          outAlpha - pointer to the output alpha channel
 * RETURN VALUES: none
 */
void pencilSketch(uint8_t *inRed,uint8_t *inBlue,uint8_t *inGreen,
                  uint8_t *inAlpha,uint8_t *invRed,uint8_t *invBlue,
                  uint8_t *invGreen,uint8_t *invAlpha,uint8_t *blurRed,
                  uint8_t *blurBlue,uint8_t *blurGreen,uint8_t *blurAlpha,
                  uint8_t *outRed,uint8_t *outBlue,uint8_t *outGreen,
                  uint8_t *outAlpha,const double *filter,int radius,
                  int width,int height,const double *gMonoMult)
{
  return;
}

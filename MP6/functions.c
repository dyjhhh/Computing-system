#include <math.h>
#include "functions.h"

/*
 * getRadius - returns the radius based on the sigma value
 * INPUTS: sigma - sigma in the Guassian distribution
 * OUTPUTS: none
 * RETURN VALUE: radius - radius of the filter
 */
int getRadius(double sigma)
{
/*The function to calculate the radius*/    
        return  ceil(3 * sigma);   
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
  int i;
  double size,value,weight,x,y;
  int radius = getRadius(sigma);
  size = 2*radius+1;
  size = size*size;
  i=0;
  weight=0;
  for(y=-radius;y <=radius ;y++)       //Loops through the filter, finishing a row then moving to the next column afterwards
    {
       
      for(x=-radius;x<=radius;x++)
	{          
	  value = (1/(sqrt(2*M_PI*sigma*sigma)))
	    *exp(-(x*x+y*y)/(2*sigma*sigma));
	  gausFilter[i] = value;                  //Puts the filter value into the filter array
	  i++;
	}
       
 
    }
  for(i=0;i<size;i++)
    {
      weight = weight + gausFilter[i];     //Calculates the weight of the filter
    }
  for(i=0;i<size;i++)
    {
      gausFilter[i] = gausFilter[i]/weight;   //Distriubtes the weight amongst the filter
    }    
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
                   int radius , int width,int height)
{
 
    int size= 2*radius+1;
    int row,column,row_checker,column_checker;  //Creates 2 sets of row/column, 1 for checking and 1 for position
 
    double red_channel=0;
    double blue_channel=0;
    double green_channel=0;
    double alpha_channel=0;
 
    for(row = 0; row < height; row++)           //Two outer loops hold the current position
    {
        for(column = 0; column < width; column++)
        {
            //Resets the values for the next check
            red_channel=0;
            blue_channel=0;
            green_channel=0;  
            alpha_channel=0;
            for(row_checker = 0; row_checker < size; row_checker++)
            {
                for(column_checker = 0; column_checker < size; column_checker++)
                {
                    if((row+row_checker-radius)<0 || (row+row_checker-radius)>=width ||  
                    (column+column_checker-radius)<0 || (column+column_checker-radius)>=height) //Used to check if the current filter position
                                                                                                //is within the boundary
                    {
                        red_channel+=0;
                        blue_channel+=0;
                        green_channel+=0;
                        alpha_channel+=0;
                    }
                    else        //If the current filter location is valid, then the filter is applied to it
                    {
                        red_channel= red_channel + inRed[width * (row + row_checker - radius) +
                        (column + column_checker - radius)]* filter[row_checker *
                        (size) + column_checker];
                       
                        blue_channel= blue_channel + inBlue[width * (row + row_checker - radius) +
                        (column + column_checker - radius)]* filter[row_checker *
                        (size) + column_checker];
 
                        green_channel= green_channel + inGreen[width * (row + row_checker - radius) +
                        (column + column_checker - radius)]* filter[row_checker *
                        (size) + column_checker];
                       
                        alpha_channel= alpha_channel + inAlpha[width * (row + row_checker - radius) +
                        (column + column_checker - radius)]* filter[row_checker *
                        (size) + column_checker];
                    }
                }
            }
           
            //If the RBG or alpha values go out of bounds, these ifs will reset them
            if(red_channel>255)
                red_channel=255;
            if(red_channel<0)
                red_channel=0;
            if(blue_channel>255)
                blue_channel=255;
            if(blue_channel<0)
                blue_channel=0;
            if(green_channel>255)
                green_channel=255;
            if(green_channel<0)
                green_channel=0;
            if(alpha_channel>255)
                alpha_channel=255;
            if(alpha_channel<0)
                alpha_channel=0;
           
            outRed[row * width + column] = red_channel;        //Puts the color value into the output array
            outBlue[row * width + column] = blue_channel;
            outGreen[row * width + column] = green_channel;
            outAlpha[row * width + column] = alpha_channel;
          }  
    }
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
  if(pixelY <= 1 || pixelX <= 1){
    int i;
    for(i = 0; i < width*height; i++){
      outRed[i] = inRed[i];
      outGreen[i] = inGreen[i];
      outBlue[i] = inBlue[i];
      outAlpha[i] = inAlpha[i];
    }
    return;
  }
  int i, j;
  for(i = 0; i < height; i+=pixelY)
  {
    for(j = 0; j < width; j+=pixelX)
    {
      double redSum = 0.0, greenSum = 0.0, blueSum = 0.0, alphaSum = 0.0;
      int x, y;
      int numPixels = 0;
      int index = i*width + j;
      for(y = 0; y < pixelY; y++)
      {
        for(x = 0; x < pixelX; x++)
        {
          int theindex = index + y*width + x;
          bool inRange = theindex < (width*height);
          bool tooRight = theindex < ((i+y)*width + width);
          bool tooLeft = theindex >= ((i+y)*width);
          if(inRange && tooRight  && tooLeft)
          {
            redSum+=inRed[theindex];
            greenSum+=inGreen[theindex];
            blueSum+=inBlue[theindex];
            alphaSum+=inAlpha[index];
            numPixels++;
          }
        }
      }
      for(y = 0; y < pixelY; y++)
      {
        for(x = 0; x < pixelX; x++)
        {
          int theindex = index + y*width + x;
          bool inRange = theindex < (width*height);
          bool tooRight = theindex < ((i+y)*width + width);
          bool tooLeft = theindex >= ((i+y)*width);
          if(inRange && tooRight && tooLeft)
          {
              outRed[theindex] = redSum / numPixels;
              outGreen[theindex] = greenSum / numPixels;
              outBlue[theindex] = blueSum / numPixels;
              outAlpha[theindex] = alphaSum / numPixels;
           
          }
        }
      }
    }
  }
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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            outRed[i] = inRed[width-1-j];
            outGreen[i] = inGreen[width-1-j];
            outBlue[i] = inBlue[width-1-j];
            outAlpha[i] = inAlpha[width-1-j];
        }
    }
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
  
    //initialize variables
    int i, j;
    double sumRed = 0;
    double sumGreen = 0;
    double sumBlue = 0;
    double sumAlpha = 0;
   
    //set up double nested for loop
    for(j = 0; j < height; j++)                        
    {                                                  
        for(i = 0; i < width; i++)                    
        {  
            sumRed = (inRed[(j)*width + (i)]);          
            sumGreen = (inGreen[(j)*width + (i)]);
            sumBlue = (inBlue[(j)*width + (i)]);
            sumAlpha = (inAlpha[(j)*width + (i)]);      
                                     
            //subtract 255 from sumRed, sumGreen, and sumBlue values, effectively inverting them.    
            outRed[i + j*width] = 255 - sumRed;
            outGreen[i + j*width] = 255 - sumGreen;
            outBlue[i + j*width] = 255 - sumBlue;
            outAlpha[i + j*width] = sumAlpha;                        
        }
    }
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

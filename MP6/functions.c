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

/*{
        int r = getRadius(sigma);
        double x, y;
        int i = 0;
        double sum = 0;
 
        for(y = -r ; y <=r ; y++)
        {
                for(x = -r ; x <= r ; x++)
                {
                      
                        gausFilter[i] = (1 / (sqrt(2 * M_PI * pow(sigma,2)))) * exp(-(pow(x, 2) + pow(y, 2)) / (2 * pow(sigma, 2)));
                        i++;
                }
               
        }
       
        i = 0;
        for(y = -r ; y <=r ; y++)
        {      
                for (x = -r; x <= r ; x++)
                {
                        sum = sum + gausFilter[i];
                        i++;
                }
        }
 
        i = 0;
        for(y = -r ; y <=r ; y++)
        {      
                for (x = -r; x <= r ; x++)
                {
                        gausFilter[i] = gausFilter[i] / sum;
                        i++;
                }
        }
 
}*/
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
		      break;
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
{ return;
  		/* int rows;
        int columns;
        int new_rows;
        int new_columns;
<<<<<<< .mine
        int r = getRadius(radius);
=======
        int pixelateSize;
>>>>>>> .r14228
 
        double Red_val = 0;
        double Blue_val = 0;
        double Green_val = 0;
        double Alpha_val = 0;
        
        for(rows=0; rows < height; rows += pixelateSize)
        {
<<<<<<< .mine
                for(columns = 0; columns < width ; columns++)
                {
                 
                  Red_val = 0;
                  Green_val = 0;
                  Blue_val = 0;
                  Alpha_val = 0;
                        for(new_rows = 0 ; new_rows < 2 * r + 1 ; new_rows++)
                        {
                                for(new_columns = 0 ; new_columns < 2 * r + 1 ; new_columns++)
                                {
                                        if( (rows + new_rows - r) < 0 || (rows + new_rows - r) >= width || (columns + new_columns - r) < 0 || (columns + new_columns - r) >= height)
                                                break;
                                        else
                                        {
                                                Red_val = Red_val + inRed[(rows + new_rows - r) * width + (columns + new_columns - r)] * filter[new_rows * (2 * r + 1) + new_columns];
                                                Blue_val = Blue_val + inBlue[(rows + new_rows - r) * width + (columns + new_columns - r)] * filter[new_rows * (2 * r + 1) + new_columns];
                                                Green_val = Green_val + inGreen[(rows + new_rows - r) * width + (columns + new_columns - r)] * filter[new_rows * (2 * r + 1) + new_columns];
                                                Alpha_val = Alpha_val + inAlpha[(rows + new_rows - r) * width + (columns + new_columns - r)] * filter[new_rows * (2 * r + 1) + new_columns];
                                        }
                                }
                        }
 
                       if(Red_val > 255)
                               Red_val = 255;
                       if(Red_val < 0)
                               Red_val = 0;
                       if(Green_val > 255)
                               Green_val = 255;
                       if(Green_val < 0)
                               Green_val = 0;
                       if(Blue_val > 255)
                               Blue_val = 255;
                       if(Blue_val < 0)
                               Blue_val = 0;
                       if
                               Alpha_
        	for(columns = 0; columns < width, columns += pixelateSize)
        	{	pixelX = pixelateSize/2;
        		pixelY = pixelateSize/2;
        		
        		while (rows + pixelX >= width) pixelX--;
        		while (columns + pixelY >= height) pixelY--;
        		
        		
        	} */
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

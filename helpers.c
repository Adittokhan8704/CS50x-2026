#include "helpers.h"
#include <math.h>
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            // Take average of red, green, and blue
image[i][j].rgbtRed = avg;
image[i][j].rgbtGreen = avg;
image[i][j].rgbtBlue = avg;
            // Update pixel values
        }
    }
}
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed =image[i][j].rgbtRed;
            int originalGreen =image[i][j].rgbtGreen;
            int originalBlue =image[i][j].rgbtBlue;
            // Compute sepia values
int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            // Update pixel with sepia values
            if(sepiaRed > 255) sepiaRed = 255;
            if(sepiaGreen > 255) sepiaGreen = 255;
            if(sepiaBlue > 255) sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            // Swap pixels
             RGBTRIPLE temp = image[i][j];
             image[i][j] = image[i][width - 1 - j];
             image[i][width - 1 - j]=temp;
        }
    }
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {


        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }






        for (int i = 0; i < height; i++)
        {

                    for (int j = 0; j < width; j++){
                                            int red = 0;
        int green = 0;
        int blue = 0;
        float count = 0.0;
                        for(int m = -1; m<=1;m++){
                            for(int n = -1; n<=1;n++){
int mi = i + m;
int nj = j +n;
if(mi>=0 && mi<height && nj >=0 && nj < width){
    red += copy[mi][nj].rgbtRed;
    blue += copy[mi][nj].rgbtBlue;
    green += copy[mi][nj].rgbtGreen;
    count ++;
}
                            }
                        }
                        image[i][j].rgbtRed = round(red/count);
image[i][j].rgbtGreen = round(green/count);
image[i][j].rgbtBlue = round(blue/count);
                    }


        }

}

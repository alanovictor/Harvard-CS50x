#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float sumcount = 0;
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width ; j++){
            sumcount += image[i][j].rgbtRed;
            sumcount += image[i][j].rgbtGreen;
            sumcount += image[i][j].rgbtBlue;
            sumcount = round(sumcount / 3);
            image[i][j].rgbtRed = sumcount;
            image[i][j].rgbtGreen = sumcount;
            image[i][j].rgbtBlue = sumcount;
            sumcount = 0;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

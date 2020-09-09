#include <stdio.h>
#include <stdlib.h>
#include "stats_lib.h"

int ReadFile (float data[]);
int main(void)
{
float nums[1000];
int n = 0; float t = 0;
float Max, Min, average, Median, Variance, Standard_deviation;
    n = ReadFile(nums);
 Max = maximum(nums,n);
 Min = minimum(nums,n);
average = mean(nums,n);
Median = median(nums,n);
Variance = variance(nums,n);
Standard_deviation = standard_deviation(nums, n);
printf("Max: %f\nMin: %f\nMean: %f\nMedian %f\nVariance: %f\nStandard_Deviation %f\n",Max,Min,average,Median,Variance,Standard_deviation);

 return 0;

}
int ReadFile (float data[])
    {
        //reading the file to get the data
    int N = 0;
    FILE *fp;
    if((fp = fopen("data.txt", "r")) == 0)
        {
            printf("File not found.  Abort!");
            exit(-1);
        }
    for(N = 0; fscanf(fp, "%f ", &data[N]) != EOF; N++)
    {
    //checking to make sure there is data and finding out how many numbers are in the sequence.
    }

    return N;
    }

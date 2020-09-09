#include "stats_lib.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float maximum(float nums[ ], int n) {
    //finds the maximum number by checking each number to the next
    float Max;
    for(int i=0;i<n;i++){
    if ( nums[i] > Max ) {
        Max = nums[i];}}


return Max;
}
float minimum(float nums[ ], int n) {
     //finds the minimum number by checking each number to the next
    float Min;
    for(int i=0;i < n;i++){
    if (nums[i] < Min){
            Min = nums[i];}}


return Min;
    }
float mean(float nums[ ], int n) {
     //finds the mean by adding each number and dividing by the total number in the sequence.
float average = 0, sum = 0;
int i = 0;

for(i = 0;i < n; i = i+1){
    sum = sum + nums[i];

}
average = (sum/i);
return average;
}
float median(float nums[ ],int n) {
//finds the median by reordering the numbers to be in order and then finding the number in the middle.
   int i,j;
   float t;
   float Median;
   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(nums[j] > nums[j+1]){
            t=nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=t;
}
            }
      }
   Median = nums[n/2];
   return Median;
}
float variance(float nums[ ], int n) {
    /*finding the variance by adding up each number and adding up the sums squared then dividing the sums by the total and
    the average squared*/
    float sum = 0, sum_sqs = 0, average= 0, Variance = 0;
    int i;
    for(i = 0; i<n; i++){
    sum += nums[i];
    sum_sqs += (nums[i]*nums[i]);
}
    average = sum;
    average = (average/i);
    Variance = ((sum_sqs)/i)-(average*average);
    return Variance;
}
float standard_deviation(float nums[], int n) {
    /*finding the standard deviation by adding up each number and adding up the sums squared then dividing the sums by
    the total and the average squared then taking the square root of all of that*/
   float sum = 0, sum_sqs = 0, average= 0, Standard_deviation = 0;
    int i;
    for(i = 0; i<n; i++){
    sum += nums[i];
    sum_sqs += (nums[i]*nums[i]);
}
    average = sum;
    average = (average/i);
    Standard_deviation = sqrt(((sum_sqs)/i)-(average*average));
    return Standard_deviation;
}


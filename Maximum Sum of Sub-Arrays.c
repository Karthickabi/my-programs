DP - Maximum Sum of Sub-Arrays 
The program must accept an array of N integers as the input. 
The program must print the maximum sum of sub-arrays in the given array as the output. 

Boundary Condition(s): 
1 <= N <= 10^6 
-1000 <= Each integer value <= 1000 

Input Format: 
The first line contains N. 
The second line contains N integers separated by a space. 

Output Format: 
The first line contains the maximum sum of sub-arrays in the given array. 

Example Input/Output 1: 
Input: 
5 
3 2 -2 5 -4
Output: 
8 
Explanation: 
The sub-array with the maximum sum 8 is given below. 
3 2 -2 5 

Example Input/Output 2: 
Input: 
3 
-5 -4 -6 
Output: 
-4
//kadane algorithm
#include<stdio.h>
#include<stdlib.h>

int main()
{
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
long int max=a[0],cur=a[0];
for(int i=1;i<n;i++)
{
    cur=a[i]<cur+a[i]?cur+a[i]:a[i];
    max=cur<max?max:cur;
}
printf("%ld",max);
}

Maximum Profit - N Cities 
A vendor wants to travel different cities to make some profit. 
In each city, he makes a profit by selling his products. 
From a city i, he can only move to a city j if and only if i < j and the profit gain from city j is a multiple of the profit gain from city i.
The program must accept an array of N integers where each integer represents the profit gain from city i (0 <= i < N). 
The program must print the maximum profit M he can gain from the N cities as the output. 

Boundary Condition(s): 
1 <= N <= 1000 
1 <= Profit gain from each city <= 10^5 

Input Format: 
The first line contains N. 
The second line contains N integers separated by a space, where each integer represents the profit gain from city i (0 <= i < N). 
Output Format: 
The first line contains M. 

Example Input/Output 1: 
Input: 
6 
1 2 3 8 21 16 
Output: 
27 
Explanation: 
The maximum profit 27 is obtained by travelling the cities 0, 1, 3 and 5. 1 + 2 + 8 + 16 = 27 
Hence 27 is printed as the output. 

Example Input/Output 2: 
Input: 
8 
2 1 3 9 2 3 18 2 
Output: 
31 

Example Input/Output 3: 
Input: 
4 
3 5 11 2 
Output: 
11

#include<stdio.h>
#include<stdlib.h>

int main()
{
int n;
scanf("%d",&n);
int a[n];
long int k[n],max;
for(int i=0;i<n;i++)
{scanf("%d",&a[i]);
k[i]=a[i];}
max=k[0];
for(int i=1;i<n;i++)
{
    
    for(int j=0;j<i;j++)
    {
        k[i]=a[i]%a[j]==0&&k[i]<k[j]+a[i]?a[i]+k[j]:k[i];
    }
    max=k[i]<max?max:k[i];
}
printf("%ld",max);
}

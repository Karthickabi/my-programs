Boy Chocolate or Ice-cream 
A boy can have either a chocolate(C) or an ice-cream(I) on a given day. 
But to avoid catching cold, his mom has prevented him from having ice-cream on consecutive days. 
The program must print the number of ways W in which the boy can have chocolate or ice-cream over the period of N days. 

Boundary Condition(s): 
1 <= N <= 80 

Input Format: 
The first line contains N. Output Format: The first line contains W. 

Example Input/Output 1: 
Input: 
3 
Output: 
5 
Explanation: 
The 5 ways to have over three days are 
C C C 
C C I 
C I C
I C C
I C I 

Example Input/Output 2: 
Input: 
5 
Output: 
13
#include<stdio.h>
void main()
{
int n;
scanf("%d",&n);
int a[n][2];
a[0][0]=a[0][1]=1;
for(int i=1;i<n;i++)
{a[i][0]=a[i-1][0]+a[i-1][1];
a[i][1]=a[i-1][0];
}
printf("%d",a[n-1][0]+a[n-1][1]);
}

DP - Array Elements Equal Left & Right Sum  
The program must accept N integers and print the integers where the sum of all integers present to it's left is equal to the sum of all integers present to it's right.
Note: At least one such integer is always present in the given integers. 

Boundary Condition(s): 
3 <= N <= 10^6 
-10^6 <= Each integer value <= 10^6 

Input Format:
The first line contains N. 
The second line contains N integers separated by a space. 

Output Format: 
The first line contains the integer value(s) separated by a space. 

Example Input/Output 1: 
Input: 
6 
7 2 1 -5 5 5 
Output: 
-5 5 

Example Input/Output 2: 
Input: 
4 
20 10 50 30 
Output: 
50

#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1],b[n+1];
    b[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]-a[i]==b[n]-b[i])
        {
            printf("%d ",a[i]);
        }
    }
}

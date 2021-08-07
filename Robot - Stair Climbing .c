Robot - Stair Climbing   
There are N stairs to be climbed in a building. 
A robot can take only S different leaps each containing certain distinct steps which are passed as the input. 
The program must print the number of ways C of steps the robot can take to climb exactly N stairs. 

Boundary Condition(s): 
1 <= N <= 50 
1 <= S <= 10 

Input Format: 
The first line contains N and S separated by a space. 
The second line contains S integer values separated by a space. 

Output Format: 
The first line contains the C. 

Example Input/Output 1: 
Input: 
5 2 
2 3 
Output: 
2
Explanation: There are 5 steps. The robot can take 2 or 3 steps at a time. So the possible ways are 2 3 and 3 2 

Example Input/Output 2: 
Input: 
6 2 
1 5 
Output: 
3 
Explanation: 
The possible ways are 
1 1 1 1 1 1 
5 1 
1 5

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    long int a[n+1];
    int b[s];
    a[0]=1;
    for(int i=1;i<=n;a[i]=0,i++);
    for(int i=0;i<s;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(b[j]<=i)
            {
                a[i]+=a[i-b[j]];
            }
        }
    }
    printf("%ld",a[n]);
}


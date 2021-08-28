Single Source Shortest Path
There are N cities in a country which are numbered from 1 to N. 
The N cities are connected by L links. Each link contains the source city, the destination city and the distance between them. 
The program must accept the values of N and L links as the input. The program must print the shortest distance from the city 1 to all the other cities as the output.

Boundary Condition(s): 
2 <= N <= 100 
1 <= L <= 1000 
1 <= Distance between any two cities <= 10^5

Input Format: 
The first line contains N and L separated by a space. 
The next L lines, each containing three integers representing the source city, the destination city and the distance between them.

Output Format: 
The first line contains N-1 integers representing the shortest distance from the city 1 to all the other cities. 

Example Input/Output 1: 
Input: 
6 7 
1 2 20 
1 6 5 
6 5 2 
5 4 3 
4 3 2 
5 2 10 
3 2 2 

Output:
14 12 10 7 5 

Explanation:
The shortest distance from the city 1 to 2 is 14 (1 -> 6 -> 5 -> 4 -> 3 -> 2). 
The shortest distance from the city 1 to 3 is 12 (1 -> 6 -> 5 -> 4 -> 3).
The shortest distance from the city 1 to 4 is 10 (1 -> 6 -> 5 -> 4). 
The shortest distance from the city 1 to 5 is 7 (1 -> 6 -> 5). 
The shortest distance from the city 1 to 6 is 5 (1 -> 6). 

Example Input/Output 2: 
Input:
5 7 
1 2 10
2 3 50
3 5 10
4 5 60
1 5 100 
1 4 30 
4 3 20 

Output:
10 50 30 60

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int a,n,f=1;
    scanf("%d%d",&a,&n);
    int dp[a+1],b[n][3];
    for(int i=1;i<=a;i++)
    dp[i]=INT_MAX;
    dp[1]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
        if(dp[b[i][0]]!=INT_MAX&&dp[b[i][1]]>dp[b[i][0]]+b[i][2])
        {
            dp[b[i][1]]=dp[b[i][0]]+b[i][2];
        }
    }
    for(int i=2;i<n&&f;i++)
    {
        f=0;
        for(int j=0;j<n;j++)
        {
            if(dp[b[j][0]]!=INT_MAX&&dp[b[j][1]]>dp[b[j][0]]+b[j][2])
            {
                dp[b[j][1]]=dp[b[j][0]]+b[j][2];
                f=1;
            }
        }
    }
    for(int i=2;i<=a;i++)
    printf("%d ",dp[i]);
}

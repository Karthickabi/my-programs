Vendor Maximum Profit  
A vendor has a shop and he wants to purchase some items for a maximum of N rupees. There are K items in a wholesale store that the vendor is going to buy. 
Each item has the cost price and profit that the seller can sell. The vendor can buy multiple items but not the same type. 
The program must accept the value of N and the cost price and profit of the K items as the input. 
The program must print the maximum profit that the vendor can earn by buying and selling the items as the output. 

Boundary Condition(s): 
1 <= N <= 1000
1 <= K <= 100 
1 <= Cost price and profit of each item <= 1000 I

nput Format: 
The first line contains N and K separated by a space. 
The next K lines, each containing two integers representing the cost price and profit of an item. 

Output Format: 
The first line contains the maximum profit that the vendor can earn by buying and selling the items as per the given conditions.

Example Input/Output 1:
Input:
10 6
5 2
6 4
3 2
4 3 
1 2
15 20 

Output: 
8 

Explanation: 
Here N = 10 and K = 6. 
The maximum profit that the vendor can earn by buying and selling the following 3 items is 8. 6 4 1 2 3 2

Example Input/Output 2:
Input: 
20 6 
5 2 
6 4 
3 2 
4 3 
1 2 
15 20 

Output: 
25

#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int max(int a,int b)
{
    return a<b?b:a;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[k][2];
    for(int i=0;i<k;i++)
    scanf("%d%d",&a[i][0],&a[i][1]);
    qsort(a,k,8,cmp);
    int dp[k+1][n+1];
    for(int i=0;i<=k;i++)
    dp[i][0]=0;
    for(int i=0;i<=n;i++)
    dp[0][i]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<a[i-1][0])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(a[i-1][1]+dp[i-1][j-a[i-1][0]],dp[i-1][j]);
            }
        }
    }
    printf("%d",dp[k][n]);
}

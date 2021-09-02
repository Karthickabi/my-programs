Subset Count Combination
The program must accept N integers as the input. The program must print the number of combinations C of the integers (1 or more integers) which add up to an even integer. 
If two or more combinations give the same even sum, then only one of those combinations will be considered. 

Boundary Condition(s): 
1 <= N <= 50 
1 <= Each integer value <= 100 

Input Format: 
The first line contains N. 
The second line contains N integers separated by a space. 

Output Format: 
The first line contains C.

Example Input/Output 1:
Input: 
4 
2 7 5 4 

Output:
7 

Explanation:
The 7 possible combinations that give an even sum are
2 
4 
2 4
7 5
2 7 5 
7 5 4 
2 7 5 4

Example Input/Output 2:
Input:
5
1 3 5 7 9 

Output: 
11

#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],sum=0,c=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    qsort(a,n,4,cmp);
    char dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int i=0;i<=sum;i++)
    dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        int curr=a[i-1];
        for(int j=1;j<=sum;j++)
        {
            if(j>=curr &&(j==curr||dp[i-1][j-curr]))
            dp[i][j]=1;
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=2;i<=sum;i+=2)
    c+=dp[n][i];
    printf("%d",c);
}

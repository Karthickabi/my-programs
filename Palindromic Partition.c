Palindromic Partition
The program must accept a string S as the input. The program must print the minimum number of cuts required so that all the substring values in S are palindromes as the output.

Boundary Condition(s): 
1 <= Length of S <= 1000 

Input Format: 
The first line contains the string S. 

Output Format: 
The first line contains the minimum number of cuts required so that all the substring values in S are palindromes. 

Example Input/Output 1:
Input: 
evening

Output:
2 
Explanation:
Here the minimum number of cuts required is 2. After two cuts in the string "evening", the palindromic substring values are "eve", "nin" and "g".

Example Input/Output 2:
Input: 
rotator 

Output: 
0 

Example Input/Output 3:
Input:
waitingnight 

Output:
7

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[1001];
    int l;
    scanf("%s%n",a,&l);
    char dp[l][l];
    int k[l];
    memset(dp,0,l*l);
    memset(k,0,l);
    for(int i=0;i<l;i++)
    {
        k[i]=i;
        for(int j=0;j<=i;j++)
        {
            if(a[i]==a[j]&&(i-j<2||dp[j+1][i-1]))
            {
                dp[j][i]=1;
                k[i]=j==0?0:k[i]<k[j-1]+1?k[i]:k[j-1]+1;
            }
        }
    }
    printf("%d",k[l-1]);
}

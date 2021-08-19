Longest Substring Length - K Unique Characters 
The program must accept a string S and an integer K as the input. 
The program must print the length of the longest substring having exactly K unique characters as the output. 

Boundary Condition(s):
1 <= Length of S <= 10^5 
1 <= K <= 26 

Input Format: 
The first line contains S and K separated by a space. 

Output Format: 
The first line contains the length of the longest substring having exactly K unique characters.

Example Input/Output 1:
Input: 
mirror 2 

Output: 
4 

Explanation: 
Here K = 2. The longest substring having exactly 2 unique characters is rror. So the length of the longest substring rror is 4.
Hence the output is 4 

Example Input/Output 2: 
Input: 
abbcdbbaabbace 3 

Output: 
8

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[100001];
    int n,l;
    int dp[128]={0};
    scanf("%s%n%d",a,&l,&n);
    int s=0,e=0,u=1,max=0;
    dp[a[0]]=1;
    while(e<l)
    {
       if(u==n)
       {
           max=max<e-s+1?e-s+1:max;
       }
       if(u<=n)
       {
           e++;
           u+=dp[a[e]]==0;
           dp[a[e]]++;
       }
       else
       {
           dp[a[s]]--;
           u-=dp[a[s]]==0;
           s++;
       }
    }
    printf("%d ",max);
}

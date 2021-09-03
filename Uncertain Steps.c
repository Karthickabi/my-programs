Uncertain Steps 
CodeVita
Codu is trying to go down stairs from his building to ground floor. He can go 3 ways. 1) Walk 1 step at a time.
2) Extend his legs and go 2 steps at a time. 3) Jump down 3 steps at a time. 
Given N steps, calculate the number of possible ways W to reach the ground floor, provided he can jump 3 steps. 
That is, he can jump down 3 steps only once, but at any time, if he wishes, while walking down the stairs.
Note: As the number of ways W can be huge, print W modulo 1000000007.

Boundary Condition(s):
1 <= N <= 10^6 

Input Format: 
The first line contains N. 

Output Format: 
The first line contains W. 

Expample Input/Output 1:
Input: 
4
Output:
7 
Explanation: 
The 7 possible ways are given below. 
1, 1, 1, 1
1, 1, 2 
1, 2, 1 
2, 1, 1 
2, 2 
1, 3 
3, 1 

Expample Input/Output 2:
Input:
5
Output:
13

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    long int a,b,c,d;
    a=1;b=1;c=1;d=2;
    for(int i=2;i<n;i++)
    {
        long int t=c;
        c=d;
        d+=t+a;
        d%=1000000007;
        t=a;
        a=b;
        b+=t;
        b%=1000000007;
    }
    printf("%ld",n==1?1:d);
}

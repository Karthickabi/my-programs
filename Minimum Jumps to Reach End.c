Minimum Jumps to Reach End
There are N stones arranged in a row. Each stone has a positive value, which indicates the maximum number of stones a person can cross in one jump from it.
A person always starts from the first stone and he wants to reach the final or last stone. The program must accept N integers representing the N stones as the input.
The program must print the minimum number of jumps that the person can reach to the last stone as the output. 

Boundary Condition(s):
1 <= N <= 10^5 
1 <= Each integer value <= 10^3 

Input Format: 
The first line contains N. 
The second line contains N integers separated by a space.

Output Format: 
The first line contains the minimum number of jumps that the person can reach to the last stone. 

Example Input/Output 1:
Input: 
5
2 3 1 1 4

Output:
2 
Explanation: 
Here the minimum number of jumps that the person can reach to the last stone is 2. 
In the 1st jump, he can jump from 2 to 3 (i.e., from the 1st stone to the 2nd stone).
In the 2nd jump, he can jump from 3 to 4 (i.e., from the 2nd stone to the 5th stone).

Example Input/Output 2: 
Input: 
14 
1 3 5 3 3 1 1 1 1 1 1 1 1 4 

Output:
9

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("0");
        return 0;
    }
    int max,step,co=1,a;
    scanf("%d",&max);
    step=max;
    for(int i=1;i<n-1;i++)
    {
        scanf("%d",&a);
        max=max<i+a?i+a:max;
        step--;
        if(step==0)
        {
            co++;
            step=max-i;
        }
    }
    printf("%d",co);
}

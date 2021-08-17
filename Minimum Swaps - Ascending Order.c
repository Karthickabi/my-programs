Minimum Swaps - Ascending Order 
The program must accept N integers from 1 to N in any order as the input. 
The program must print the minimum number of swaps required to order those N integers in ascending order as the output. 

Boundary Condition(s): 
1 <= N <= 1000 

Input Format: 
The first line contains N. 
The second line contains N integers separated by a space. 

Output Format: 
The first line contains the minimum number of swaps required. 

Example Input/Output 1: 
Input: 
5 
2 3 1 5 4 

Output: 
3

Explanation: The integers 5 and 4 can be swapped. Now the integers become 2 3 1 4 5. Then the integers 2 and 1 can be swapped. Now the integers become 1 3 2 4 5. 
Then the integers 3 and 2 can be swapped. Now the integers become 1 2 3 4 5. So at least 3 swaps are required. Hence 3 is printed. 

Example Input/Output 2: 
Input: 
7 
2 7 6 3 5 4 1 

Output: 
4
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    int a[n+1];
    char c[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i])
        continue;
        if(a[i]==i)
        {
            c[i]=1;
            continue;
        }
        int e=0,cyc=i;
        while(!c[a[cyc]])
        {
            c[a[cyc]]=1;
            e++;
            cyc=a[cyc];
        }
        ans+=(e-1);
    }
    printf("%d",ans);
}

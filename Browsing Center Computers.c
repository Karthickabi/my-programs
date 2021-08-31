Browsing Center Computers
In a browsing center, the owner accepts the next day's browsing slot booking from N customers via internet.
Each browsing slot contains the start time and the end time in 24-hr format. The browsing center owner must have at least M computers so that no one is waiting.
The browsing solt of N customers are passed as the input. The program must print the minimum number of computers M so that no one is waiting in the center.

Boundary Condition(s):
1 <= N <= 10^5

Input Format:
The first line contains N. The next N lines, each containing the start time and the end time of a browsing slot.

Output Format:
The first line contains M.

Example Input/Output 1:
Input:
6
9:00 11:00
9:30 10:30
9:30 12:00 
9:45 13:00 
11:00 15:00
10:00 14:00 

Output:
5
Explanation: 
The browsing center owner must have at least 5 computers so that no one is waiting.
At 10:00, there must be at least 5 computers.

Example Input/Output 2:
Input:
6
9:00 15:00 
10:00 10:30 
11:00 13:00 
13:00 14:00 
14:30 15:00 
14:30 16:00

Output: 
3

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
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        int c,d,e,f;
        scanf("%d:%d %d:%d",&c,&d,&e,&f);
        a[i]=c*100+d;b[i]=e*100+f;
    }
    qsort(a,n,4,cmp);
    qsort(b,n,4,cmp);
    int s=0,e=0,max=0;
    while(s<n)
    {
        max=s-e+1<max?max:s-e+1;
        if(a[s]<b[e])
        {
            s++;
        }
        while(e<n&&s<n&&a[s]>=b[e])
        e++;
    }
    printf("%d",max);
}

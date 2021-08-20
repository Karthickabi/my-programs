Non-Measurable Smallest Weight
A shop-keeper is having N integer values representing the measurement weights. 
He wishes to find the smallest integer value of weight that cannot be measured using these N weights. 
Please help the shop keeper by completing the program.

Boundary Condition(s):
1 <= N <= 1000 
1 <= Each weight value <= 500

Input Format:
The first line contains N. 
The second line contains the N integer values separated by a space. 

Output Format:
The first line contains an integer value. 

Example Input/Output 1:
Input: 
4 
2 4 1 10 

Output: 
8 

Explanation: 
1, 2, 4 and 10 can be measured using the given single measurement. 
3 - 1 and 2 5 - 1 and 4 6 - 2 and 4 7 - 1, 2 and 4 8 - cannot be measured and hence is printed as the output.

Example Input/Output 2: 
Input: 
5 
1 4 2 4 3 

Output: 
15

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
    int a[n],m=1;
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    qsort(a,n,4,cmp);
    for(int i=0;i<n&&a[i]<=m;i++)
    {
        m+=a[i];
    }
    printf("%d",m);
}

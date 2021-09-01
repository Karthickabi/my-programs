Finding Sum
CodeVita 
The program must accept N integers and an integer P as the input. The program must print the number of subsets of size 3, the sum of whose elements is divisible by P. 
Since the number K of such subsets can be huge, the program must print K modulo 1009 as the output. 
Note: The integer P is always a prime number. 

Boundary Condition(s): 
1 <= N <= 10000
1 <= P <= 50 
1 <= Each integer value <= 1000 

Input Format: 
The first line contains N and P separated by a comma. 
The second line contains N integers separated by a comma. 

Output Format: 
The first line contains K modulo 1009. 

Example Input/Output 1:
Input:
4,5 
5,10,15,20

Output: 
4 
Explanation:
The 4 possible subsets are given below. 
5 10 15
5 10 20
5 15 20 
10 15 20 

Example Input/Output 2: 
Input: 
6,7 
4,3,8,6,5,2

Output: 
2 
Explanation:
The 2 possible subsets are given below.
3 6 5 
4 8 2

#include<stdio.h>
#include<stdlib.h>
#define ULL unsigned long long int
int main()
{
    int n,d;
    ULL c=0;
    scanf("%d,%d",&n,&d);
    int a[d],k;
    memset(a,0,4*d);
    for(int i=0;i<n;i++)
    {
        scanf("%d,",&k);
        a[k%d]++;
    }
    for(int i=0;i<d;i++)
    {
        for(int j=i;j<d;j++)
        {
            int k=(d-(i+j)%d)%d;
            if(k<j)
            {
                continue;
            }
            if(i==j&&i==k)
            {
                c+=((ULL)a[i]*(a[i]-1)*(a[i]-2))/6;
            }
            else if(i==j)
            {
                c+=((a[i]*(a[i]-1))/2)*a[k];
            }
            else if(i==k)
            {
                c+=((a[i]*(a[i]-1))/2)*a[j];
            }
            else if(j==k)
            {
                c+=((a[j]*(a[j]-1))/2)*a[i];
            }
            else
            c+=a[i]*a[j]*a[k];
            c%=1009;
        }
    }
    printf("%llu",c);
}

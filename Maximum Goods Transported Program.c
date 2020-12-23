/*
Maximum Goods Transported Program: There are goods to be transported by trains through a series of N stations which are numbered from 1 to N. Each station has at most one incoming railroad and at most one outgoing railroad. There are T tracks and each track connecting two stations has a capacity limit to transport goods. The stations with no incoming railroad are the sources and the stations with no outgoing railroad are the destinations. The program must print the maximum amount of goods that can be transported.

Boundary Condition(s):
2 <= N <= 30
1 <= T <= 60
1 <= capacity <= 1000

Input Format:
The first line contains N and T separated by space(s).
The next T lines contain starting station number, ending station number and capacity limit of the track each separated by space(s). 

Example Input/Output 1:
6 4
1 2 23
3 4 12
5 6 34
2 3 45

Output:
46

Explanation:
Goods are transported through the following routes,
1->2->3->4 = 12
5->6 = 34

Example Input/Output 2:
9 6
3 4 23
1 2 56
2 6 14
7 9 54
5 7 16
8 5 23

Output:
53

Explanation:
Goods are transported through the following routes,
3->4 = 23
1->2->6 = 14
8->5->7->9 = 16
                                                               ---------------COMPLETED-----------------
*/
#include<stdio.h>
#include <stdlib.h>
void v(int *a,int b,int c,int d,char *k)
{if(k[c])
{while(a[b]<0)
b=abs(a[b]);
a[b]=d;
return;}
while(a[c]<0)
c=abs(a[c]);
a[c]=a[c]==0?d:a[c]<d?a[c]:d;
while(a[b]<0)
b=abs(a[b]);
a[b]=-c;}
int main(){
int n,b,c,d,e;
scanf("%d%d",&n,&b);
int a[n];char k[n];
for(int i=0;i<n;i++)
a[i]=k[i]=0;
for(int i=0;i<b;i++)
{scanf("%d%d%d",&c,&d,&e);
v(a,c-1,d-1,e,k);
k[d-1]=1;}b=0;
for(int i=0;i<n;i++)
b+=(a[i]>0?a[i]:0);
printf("%d",b);}

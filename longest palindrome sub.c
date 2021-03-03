//Manachar’s Algorithm
#include<stdio.h>
#include<stdlib.h>
int P[200002]={0};
void v(char *a,int n)
{char k[(n*2)+4];int l=1,c=0,r=0;
k[0]='@';
for(int i=0;i<n;i++)
{k[l++]='#';
k[l++]=a[i];}k[l++]='#';k[l]='\0';
for(int i = 1; i < l-1; i++)
{int m = c - (i - c);        
if(r>i)           
P[i]=r-i<P[m]?r-1:P[m];                  
while (k[i + 1 + P[i]] == k[i - 1 - P[i]])
P[i]++;                
if (i + P[i] > r) 
{c = i;                          
r =i+P[i];}}r=0;
for(int i=1;i<l-1;i++)
{printf("%d ",P[i]);
r=r<P[i]?P[i]:r;}
printf("%d ",r);}
int main()
{char a[100001];int n;
scanf("%s%n",a,&n);
v(a,n);}

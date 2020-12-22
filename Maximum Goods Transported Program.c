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

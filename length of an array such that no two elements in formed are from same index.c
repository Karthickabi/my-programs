//length of an array such that no two elements in formed are from same index given the array frequencies 
#include <stdio.h>
int main()
{int a,b,c,k=0;
scanf("%d%d",&a,&b);
for(int i=0;i<a-1;i++)
{scanf("%d",&c);
if(b>c)
{k+=c*2;
b-=c;
}else
{int t=k;
k+=b*2;
c-=b;
k=c<t+1?k+c:k+t+1;
b=c<=t+1?0:c-t-1;}}
printf("%d ",k);}

long int fat(long int a)
{return a>4?(a/10)+1:0;}
#include <stdio.h>
int main()
{long int a,b,c=0,i,l=3;
scanf("%ld",&a);
c=a%3==0?1:0;
c=a%5==0?c+fat(a):c;
b=(a-a%3)-3;
for(i=b;i>2;i-=l)
{if((a-i)%5==0)
{c+=fat(a-i);
l=15;}}
printf("%ld ",c);}

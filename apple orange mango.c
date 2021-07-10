#include<math.h>
#include <stdio.h>
long long int f(long long int a)
{return a*(a<1?1:f(a-1));}
long long int c(long long int a,long long int b)
{ return f(a)/(f(a-b)*f(b));}
int main()
{long long int a,b,k=1,n,s;
scanf("%lld%lld",&a,&b);
n=a/b;
s=pow(2,a--);
for(int i=0;i<n;i++)
s+=(pow(2,a--)*c(n,k++));
printf("%lld",s);}

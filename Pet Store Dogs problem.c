#include <stdio.h>
long double f(long double a)
{if(a<=1)
return 1;
return a*f(a-1);}
int main()
{long double sum=1,val,a;
scanf("%Lf",&a);
val=f(a);
for(int i=1;i<=a/2;i++)
{long double k=val;
k/=(long double)(1<<i);
k/=f(a-(2*i));
k/=f((long double)i);
printf("%.LF\n",k);
sum+=k;
}
printf("%.Lf",sum);
}}

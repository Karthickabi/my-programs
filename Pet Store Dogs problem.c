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
}/*
There are N dogs in a pet store. The pet store wants to keep the N dogs in cages.
There can be two dogs in each cage. A dog can be eitheir passive or aggressive.
If the dog is passive, it can be clubed with another passive dog.
If the dog is aggressive, it has to be alone in a cage.
The program must print the number ways W to put the N dogs in the cages as the output.
Note: The number of cages in the pet store is sufficient to keep N dogs according to the given condition.
*/

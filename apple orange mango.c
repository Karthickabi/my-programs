#include<math.h>
#include <stdio.h>
long long int f(long long int a)
{return a<1?1:a*f(a-1);}
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

//dp method
#include <stdio.h>
int main()
{int n,k;
scanf("%d%d",&n,&k);
int a[n][3];
a[0][0]=a[0][1]=1;
a[0][2]=k==1?1:0;
for(int i=1;i<n;i++)
{a[i][2]=0;
a[i][0]=a[i][1]=a[i-1][0]+a[i-1][0]+a[i-1][2];
if((i+1)%k==0)
a[i][2]+=a[i-1][1]+a[i-1][0]+a[i-1][2];
}
for(int i=0;i<n;i++)
printf("%d ",a[i][0]);
printf("\n");
for(int i=0;i<n;i++)
printf("%d ",a[i][1]);
printf("\n");
for(int i=0;i<n;i++)
printf("%d ",a[i][2]);
printf("\n%d",a[n-1][0]+a[n-1][1]+a[n-1][2]);
}

//easiest method
#include <stdio.h>
int main()
{long long int k,n,p,a=1;
scanf("%lld%lld",&n,&k);
p=k==1;
for(int i=1;i<=n;i++)
{a=(a<<1)+p;
p=(i+1)%k?0:a;
}
printf("%lld",a);
}

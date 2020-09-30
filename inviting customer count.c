//inviting customer count
#include <stdio.h>
int main()
{int n,d,t,c=1,f=1,k=1,h=0;
scanf("%d%d%d",&n,&d,&t);
int a[d];
f+=(f*n);
a[0]=f;
for(int i=1;i<t-1;i++)
{a[k++]=f*n;
f+=(f*n);
c++;
if(c>=d)
{f-=a[h++];
h=h==d?0:h;}
k=k==d?0:k;}
printf("%d ",f);
}

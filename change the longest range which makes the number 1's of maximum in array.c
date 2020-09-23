//change the longest range which makes the number 1's of maximum in array 
#include <stdio.h>
int main()
{char a[100];
int n0=0,l,s=0,e=0,max=0,s1,e1,f;
scanf("%s",a);
l=strlen(a);
for(int i=0;i<l;i++)
{if(a[i]=='0')
{s=i;
n0=1;i++;f=0;
while(i<l&&n0>0/*n0>n1*/)
{n0=a[i]=='0'?n0+1:n0-1;
/*if(a[i]=='0')
n0++;
else
n1++;
if(n0-n1>f)
*/
if(n0>f)
{f=n0;
e=i;}i++;}
if(f>max)
{max=f;
s1=s;
e1=e;}i--;/*n1=n2=0*/}}
for(int i=s1;i<=e1;i++)
a[i]=a[i]=='1'?'0':'1';
printf("%s",a);
}

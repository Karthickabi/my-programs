//MOCKVITA 2018 height of the students
#include <stdio.h>
void h(char a,char b,char t[][2],int i)
{if(b==0)
return;
if(t[a-'A'][i]==0)
t[a-'A'][i]=b;
else
{char f=t[a-'A'][i];
while(f!=b&&f!=0)
f=t[f-'A'][i];
if(f==0)
t[a-'A'][i]=b;}}
int main()
{int r,c,k,p=0;
scanf("%d,%d",&r,&c);
char a[r][2],t[r+1],f,te;
memset(a,0,r*3);
for(int i=0;i<c-1;i++)
{k=0;
while(scanf(" %c%c ",&t[k],&te)==2)
{if(k>0)
h(t[k-1],t[k],a,1);
if(k>1)
h(t[k-1],t[k-2],a,0);
if(te=='\r'||te=='\n')
break;
k++;}h(t[k],t[k-1],a,0);}
k=0;
while(scanf("%c,",&t[k])==1)
{if(k>0)
h(t[k-1],t[k],a,1);
if(k>1)
h(t[k-1],t[k-2],a,0);
k++;}
h(t[k-1],t[k-2],a,0);
for(int j=0;j<r;j++)
printf("%c,%c,%c\n",a[j][0],'A'+j,a[j][1]);
printf("\n");}

#include<stdio.h>
#include<stdlib.h>
void p(int n,int a[][n],int h1,int dp,int sum,int k[][2],int *l,int b,int c)
{if(b<0||b>=n||c<0||c>=n||a[b][c]==0)
return;
if(a[b][c]==1)
{k[*l][0]=b;k[(*l)++][1]=c;a[b][c]=sum;}
p(n,a,h1,dp,sum,k,l,b+(h1?dp:0),c+(h1?0:dp));}
void v(int n,int a[][n],int d,int e,int k[][2],int l,int s)
{int k1[1000][2],l1=0;
for(int i=0;i<l;i++)
{if(k[i][0]==d&&k[i][1]==e)
return; 
p(n,a,1,1,-s,k1,&l1,k[i][0]+1,k[i][1]);
p(n,a,1,-1,-s,k1,&l1,k[i][0]-1,k[i][1]);
p(n,a,0,1,-s,k1,&l1,k[i][0],k[i][1]+1);
p(n,a,0,-1,-s,k1,&l1,k[i][0],k[i][1]-1);}
v(n,a,d,e,k1,l1,s+1);}
int main(){
int n,d,e;
scanf("%d",&n);
int a[n][n],k[1][2];
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
scanf("%d",&a[i][j]);}
scanf("%d%d%d%d",&k[0][0],&k[0][1],&d,&e);
a[k[0][0]][k[0][1]]=-1;
v(n,a,d,e,k,1,1);
printf("%d",abs(a[d][e]));}

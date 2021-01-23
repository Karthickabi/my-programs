#include <stdio.h>
int isvalid(int r,int c,char a[][c],int i,int j)
{return i<r&&j<c&&i>=0&&j>=0&&a[i][j];}
void v(int r,int c,char a[][c],int n[][2],int k,int days,char dp[][c])
{int f[r*c][2],l=0,t=0;
for(int i=0;i<k;i++)
{if(a[n[i][0]][n[i][1]]!=0)
{f[l][0]=n[i][0];f[l++][1]=n[i][1];
a[n[i][0]][n[i][1]]--;
}else
{if(isvalid(r,c,dp,n[i][0]+1,n[i][1]))
{f[l][0]=n[i][0]+1;f[l++][1]=n[i][1];
a[n[i][0]+1][n[i][1]]--;dp[n[i][0]+1][n[i][1]]=0;t=1;}
if(isvalid(r,c,dp,n[i][0],n[i][1]+1))
{f[l][0]=n[i][0];f[l++][1]=n[i][1]+1;
a[n[i][0]][n[i][1]+1]--;dp[n[i][0]][n[i][1]+1]=0;t=1;}
if(isvalid(r,c,dp,n[i][0]-1,n[i][1]))
{f[l][0]=n[i][0]-1;f[l++][1]=n[i][1];
a[n[i][0]-1][n[i][1]]--;dp[n[i][0]-1][n[i][1]]=0;t=1;}
if(isvalid(r,c,dp,n[i][0],n[i][1]-1))
{f[l][0]=n[i][0];f[l++][1]=n[i][1]-1;
a[n[i][0]][n[i][1]-1]--;dp[n[i][0]][n[i][1]-1]=0;t=1;}
}}
for(int i=0;i<l;i++)
printf("%d,%d ",f[i][0],f[i][1]);
printf("\n");
for(int i=0;i<r;i++)
{for(int j=0;j<c;j++)
printf("%d ",a[i][j]);
printf("\n");
}
if(l==0)
{printf("%d ",days);
return;}
v(r,c,a,f,l,days+1,dp);
}
int main()
{int r,c;
scanf("%d%d",&r,&c);
char a[r][c],b[3],dp[r][c];int n[r*c][2],k=0;
for(int i=0;i<r;i++)
{for(int j=0;j<c;j++)
{scanf("%s",b);dp[i][j]=1;
if(strcmp(b,"RA")==0)
a[i][j]=0;
else if(strcmp(b,"RB")==0)
a[i][j]=1;
else 
a[i][j]=b[0]=='A'?1:2;
if(b[0]=='R')
{n[k][0]=i;
n[k++][1]=j;
dp[i][j]=0;
}}}for(int i=0;i<r;i++)
{for(int j=0;j<c;j++)
printf("%d ",a[i][j]);
printf("\n");
}
if(k==r*c)
printf("0");
else
v(r,c,a,n,k,0,dp);
}/*
4 4
RA A B B
B A A B
A RB RA A
B A B A*/

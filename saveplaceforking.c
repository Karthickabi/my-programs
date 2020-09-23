void R(int r,int c,char a[r][c],int i,int j)
{int i1=i+1,j1=j;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&i1<r)
a[i1++][j1]='0';
i1=i-1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&i1>=0)
a[i1--][j1]='0';
i1=i;j1=j+1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&j1<c)
a[i1][j1++]='0';
j1=j-1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&j1>=0)
a[i1][j1--]='0';
}
void B(int r,int c,char a[r][c],int i,int j)
{int i1=i+1,j1=j+1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&(i1<r&&j1<c))
a[i1++][j1++]='0';
i1=i+1;j1=j-1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&(i1<r&&j1>=0))
a[i1++][j1--]='0';
i1=i-1;j1=j-1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&(i1>=0&&j1>=0))
a[i1--][j1--]='0';
i1=i-1;j1=j+1;
while((a[i1][j1]=='*'||a[i1][j1]=='0')&&(i1>=0&&j1<c))
a[i1--][j1++]='0';
}
void Q(int r,int c,char a[r][c],int i,int j)
{R(r,c,a,i,j);
B(r,c,a,i,j);
}
void K(int r,int c,char a[r][c],int i,int j)
{if(a[i+2][j+1]=='*'&&i+2<r&&j+1<c)
a[i+2][j+1]='0';
if(a[i+2][j-1]=='*'&&i+2<r&&j-1>=0)
a[i+2][j-1]='0';
if(a[i-2][j+1]=='*'&&i-2>=0&&j+1<c)
a[i-2][j+1]='0';
if(a[i-2][j-1]=='*'&&i-2>=0&&j-1>=0)
a[i-2][j-1]='0';
if(a[i+1][j+2]=='*'&&i+1<r&&j+2<c)
a[i+1][j+2]='0';
if(a[i-1][j+2]=='*'&&i-1>=0&&j+2<c)
a[i-1][j+2]='0';
if(a[i+1][j-2]=='*'&&i+1<r&&j-2>=0)
a[i+1][j-2]='0';
if(a[i-1][j-2]=='*'&&i-1>=0&&j-2>=0)
a[i-1][j-2]='0';
}
#include <stdio.h>
int main()
{int n,k,x,y,c=0;
scanf("%d",&n);
char a[n][n],b[4]={'K','R','B','Q'};
memset(a, '*', n*n);
for(int i=0;i<4;i++)
{scanf("%d",&k);
for(int j=0;j<k;j++)
{scanf("%d %d",&x,&y);
a[x][y]=b[i];
}}
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{if(a[i][j]=='K')
K(n,n,a,i,j);
if(a[i][j]=='B')
B(n,n,a,i,j);
if(a[i][j]=='Q')
Q(n,n,a,i,j);
if(a[i][j]=='R')
R(n,n,a,i,j);
}}
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
c+=(a[i][j]=='*');
}printf("%d",c);}

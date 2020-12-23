/*
Knight Kills King: A knight in a chess game is determined to kill the enemy king. The chess board is of the size N*N. The knight can move through the empty cells but he cannot land on a cell where friendly units are placed. The knight is represented as K, the friendly units are represented as F, the enemy king is represented as E and the empty cells are represented as X. Find the minimum number of moves needed for the knight to reach the enemy king. The knight moves to a square that is two squares away horizontally and one square vertically, or two squares vertically and one square horizontally. The complete move therefore looks like the letter L.

Boundary Condition(s):
1 <= N <= 1000

Input Format:
The first line contains N.
The next N lines represent the chess board.

Output Format:
The first line contains the minimum number of moves required to reach the enemy king by the knight.

Example Input/Output 1:
Input:
5
KXXXX
XXXXX
XXXXX
XXXEX
XXXXX

Output:
2

Example Input/Output 2:
Input:
7
EXXXXXX
XXXXXXX
FFXXXXX
XXKXXXX
FXXXXFX
XXXXXXX
XXXXXXX

Output:
3
                                                -------------------COMPLETED--------------------
*/#include <stdio.h> 
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
int isInside(int x, int y, int N) 
{return(x >=0 && x <N && y >=0 && y < N);}
int m(int n,char a[][n],int f[][n],int kn,int k[][2],int x,int y)
{int h=0,kh[100][2];
for(int i=0;i<kn;i++)
{if(k[i][0]==x&&k[i][1]==y)
return f[x][y];
for(int j=0;j<8;j++)
{if(isInside((k[i][0]+dx[j]),(k[i][1]+dy[j]),n)&&f[k[i][0]+dx[j]][k[i][1]+dy[j]]!=-2&&f[k[i][0]+dx[j]][k[i][1]+dy[j]]==-1&&f[k[i][0]][k[i][1]]!=-2)
{f[k[i][0]+dx[j]][k[i][1]+dy[j]]=f[k[i][0]][k[i][1]]+1;
kh[h][0]=k[i][0]+dx[j];
kh[h][1]=k[i][1]+dy[j];
h++;}}}return m(n,a,f,h,kh,x,y);}
int main() 
{int n,x,y,ex,ey;
scanf("%d",&n);
char a[n][n];
int k[100][2],f[n][n],h=0;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
f[i][j]=-1;}
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{scanf(" %c ",&a[i][j]);
if(a[i][j]=='F')
f[i][j]=-2;
if(a[i][j]=='K')
{f[i][j]=0;
for(int p=0;p<8;p++)
{if(isInside(i+dx[p],j+dy[p],n)&&f[i+dx[p]][j+dy[p]]!=-2)
{f[i+dx[p]][j+dy[p]]=1;
k[h][0]=i+dx[p];
k[h][1]=j+dy[p];
h++;}}}
if(a[i][j]=='E')
{x=i;
y=j;}}}printf("%d ",m(n,a,f,h,k,x,y));}

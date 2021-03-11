/*N Rooks - Fill Remaining
In a N*N square chessboard, certain number of rooks are placed. 
The program must accept the positions of R rooks (marked by 1). 
The empty squares are marked by the value 0. 
The program must fill in the remaining N-R rooks with the condition that only one rook must be in a row and one rook must be in a column so that the rooks do not attack each other. 
The program must finally print the arrangement of the rooks in the chessboard 
(if multiple arrangements are possible print the possibility which occurs with the left most column filled starting from the top row). 
Note: In Chess, a rook can move along a row or a column. 
The movement can happen till the end of the board is reached or another piece (like Rook, Knight, Bishop, Pawn etc is encountered). 
But in this program only the N rooks are placed and no other pieces will be present on the board. 
Boundary Condition(s):
2 <= N <= 20 0 <= R <= N-1

Input Format: 
The first line contains N. The next N lines contain N values (0 or 1) each separated by a space. 

Output Format: 
The first N lines contain N values (0 or 1) each separated by a space. 

Example Input/Output 1:
Input: 
4 
1 0 0 0 
0 0 0 0 
0 0 0 1 
0 1 0 0 

Output: 
1 0 0 0 
0 0 1 0 
0 0 0 1 
0 1 0 0 

Example 
Input/Output 2: 
Input: 
3 
0 0 0 
0 0 0 
0 0 0 
Output:
1 0 0 
0 1 0 
0 0 1 
Explanation: Here multiple arrangements are possible. 
But starting from the top row, we consider the possibility once the left most column is filled.
*/
#include<stdio.h>
#include<stdlib.h>
int v(int n,char a[][n],char *b,char *c,int k)
{if(k==n)
return 1;
if(b[k])
return v(n,a,b,c,k+1);
for(int i=0;i<n;i++)
{if(!c[i])
{a[k][i]=b[k]=c[i]=1;
if(v(n,a,b,c,k+1))
return 1;
a[k][i]=b[k]=c[i]=0;
}}return 0;}
int main()
{int n;
scanf("%d",&n);
char a[n][n],b[n],c[n];
for(int i=0;i<n;i++)
b[i]=c[i]=0;
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
{scanf("%d",&a[i][j]);
if(a[i][j])
b[i]=c[j]=1;}}
if(v(n,a,b,c,0))
{for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
printf("%d ",a[i][j]);
printf("\n");
}}else
printf("NotPossible");}

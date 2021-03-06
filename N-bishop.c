/*N Bishops - 
Fill Remaining ID:12942 
In a N*N square chessboard, certain number of bishops are placed. 
The program must accept the positions of B bishops(marked by 1). 
The empty squares are marked by the value 0. 
The program must fill in the remaining N-B bishops with the condition that only one bishop must be in a row and one bishop must be in a column so that the bishops do not attack each other.
The program must finally print the arrangement of the bishops in the chessboard 
(if multiple arrangements are possible print the possibility which occurs with the left most column filled starting from the top row). 
If such an arrangement is not possible, then the program must print NotPossible as the output. Note: In Chess, a bishop can move diagonally.
The movement can happen till the end of the board is reached or another piece (like Rook, Knight, Bishop, Pawn etc is encountered).
But in this program only the N bishops are placed and no other pieces will be present on the board. 
Boundary Condition(s): 
2 <= N <= 20 0 <= B <= N-1 
Input Format: 
The first line contains N. 
The next N lines contain N values (0 or 1) each separated by a space.
Output Format: T
he first N lines contain N values (0 or 1) each separated by a space. 
Example 
Input/Output 1: 
Input: 
4 
1 0 0 0 
0 0 0 0 
0 0 0 1 
0 1 0 0 
Output: 
1 0 0 0 
1 0 0 0 
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
1 0 0 
1 0 0
Explanation: 
Here multiple arrangements are possible.
But starting from the top row, we consider the possibility once the left most column is filled.
Example Input/Output 3:
Input: 4 
1 0 0 0 
0 0 0 0 
0 1 0 0 
0 0 0 0 
Output: 
NotPossible
*/
#include<stdio.h>
#include<stdlib.h>
int v(int n,char a[][n],char *b,char *c,char *d,int k)
{if(k==n)
return 1;
if(d[k])
return v(n,a,b,c,d,k+1);
for(int i=0;i<n;i++)
{if(!c[i-k+n-1]&&!b[k+i]){
a[k][i]=d[k]=b[k+i]=c[i-k+n-1]=1;
if(v(n,a,b,c,d,k+1))
return 1;
else
a[k][i]=d[k]=b[k+i]=c[i-k+n-1]=0;
}}return 0;}
int main()
{int n;
scanf("%d",&n);
char a[n][n],b[2*n-1],c[2*n-1],d[n];
for(int i=0;i<2*n-1;i++)
b[i]=c[i]=0;
for(int i=0;i<n;i++)
{d[i]=0;
for(int j=0;j<n;j++)
{scanf("%d",&a[i][j]);
if(a[i][j])
d[i]=b[i+j]=c[j-i+n-1]=1;}}
if(v(n,a,b,c,d,0))
{for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
printf("%d ",a[i][j]);
printf("\n");
}}else
printf("NotPossible");}

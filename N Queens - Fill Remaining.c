N Queens - Fill Remaining
In a N*N square chessboard, Q queens are placed in Q continuous rows so that they do not attack each other.
The program must accept the positions of the Q queens (marked by 1) and print the positions of the remaining N-Q queens in the remaining rows to be placed,
so that they do not attack each other. Note: In Chess, queen can move any direction diagonally. The queen can also move left or right along the row it is present.
The queen can also move up or down along the column it is present.
The movement can happen till the end of the board is reached or another piece (like Rook, Knight, Bishop, Pawn etc is encountered).
But in this program only the N queens are placed and no other pieces will be present on the board.
Boundary Condition(s): 
4 <= N <= 10 
2 <= Q <= N-1

Input Format:
The first line contains N. The next N lines contain N values (0 or 1) each separated by a space.

Output Format: 
The first line contains the shift in the position followed by the direction. 

Example Input/Output 1:
Input: 
4 
0 1 0 0
0 0 0 1
0 0 0 0 
0 0 0 0 

Output: 
0 1 0 0 
0 0 0 1 
1 0 0 0
0 0 1 0 

Explanation: 
In this combination the queens do not attack each other. 

Example Input/Output 2:
Input: 
8 
0 0 1 0 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 
1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 

Output: 
0 0 1 0 0 0 0 0 
0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 
1 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 0 1 0 
0 0 0 0 1 0 0 0 
0 1 0 0 0 0 0 0

#include<stdio.h>
#include<stdlib.h>
int v(int n,char a[][n],char r[],char c[],char d1[],char d2[],int dp)
{
    if(dp==n)
    return 1;
    if(r[dp])
    return v(n,a,r,c,d1,d2,dp+1);
    for(int i=0;i<n;i++)
    {
        if(!r[dp]&&!c[i]&&!d1[dp+i]&&!d2[i-dp+n-1])
        {
            a[dp][i]=r[dp]=c[i]=d1[dp+i]=d2[i-dp+n-1]=1;
            if(v(n,a,r,c,d1,d2,dp+1))
            return 1;
            else
            a[dp][i]=r[dp]=c[i]=d1[dp+i]=d2[i-dp+n-1]=0;
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char a[n][n],r[n],c[n],d1[n*2],d2[n*2];
    memset(r,0,n);
    memset(c,0,n);
    memset(d1,0,n*2);
    memset(d2,0,n*2);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])
            {
                r[i]=1;
                c[j]=1;
                d1[i+j]=1;
                d2[j-i+n-1]=1;
            }
        }
    }
    if(v(n,a,r,c,d1,d2,0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    else
    printf("NotPossible");
}

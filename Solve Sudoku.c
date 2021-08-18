Solve Sudoku   
The program must accept an integer matrix of size 9x9 representing a sudoku as the input. 
The sudoku matrix contains the integers from 0 to 9 where 0 represents the empty cells. 
If the sudoku matrix is valid, the program must fill in the empty cells of the sudoku matrix and print it as the output.
Else the program must print Not Solved as the output. Sudoku: Sudoku is a logic-based, combinatorial number-placement puzzle. 
The objective is to fill a 9×9 grid with digits so that each column, each row, and each of the nine 3×3 subgrids that compose the grid contain all of the digits from 1 to 9. 

Input Format: 
The first 9 lines each contain 9 integers separated by a space. 

Output Format: 
The first 9 lines each contain 9 integers separated by a space or the first line contains Not Solved. 

Example Input/Output 1: 
Input:
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0 
1 9 0 0 0 4 5 0 0 
8 2 0 1 0 0 0 4 0 
0 0 4 6 0 2 9 0 0 
0 5 0 0 0 3 0 2 8 
0 0 9 3 0 0 0 7 4 
0 4 0 0 5 0 0 3 6 
7 0 3 0 1 8 0 0 0 

Output: 
4 3 5 2 6 9 7 8 1 
6 8 2 5 7 1 4 9 3
1 9 7 8 3 4 5 6 2 
8 2 6 1 9 5 3 4 7
3 7 4 6 8 2 9 1 5
9 5 1 7 4 3 6 2 8
5 1 9 3 2 6 8 7 4 
2 4 8 9 5 7 1 3 6 
7 6 3 4 1 8 2 5 9 

Example Input/Output 2: 
Input: 
0 6 0 3 0 0 8 0 4 
5 3 7 0 9 0 0 0 0 
0 4 0 0 0 6 3 0 7 
0 9 0 0 5 1 2 3 8 
0 0 0 0 0 0 0 0 0 
7 1 3 6 2 0 0 4 0 
3 0 6 4 0 0 0 1 0 
0 0 0 0 6 0 5 2 3 
1 0 2 0 0 3 0 8 0 

Output: 
Not Solved

#include <stdio.h>
#include <stdlib.h>
#define N 9
int r[9]={1},c[9]={1},s[9]={1};
void print(int arr[N][N])
{    
    for (int i = 0; i < N; i++)    
    {        
        for (int j = 0; j < N; j++)            
        printf("%d ",arr[i][j]);        
        printf("\n");    
    }
}
int isSafe(int row,int col, int num)
{    
    return !((r[row]>>num)&1)&&!((c[col]>>num)&1)&&
    !((s[(row/3)*3+(col/3)]>>num)&1);
}
int solveSuduko(int grid[N][N], int row, int col)
{    
    if (row == N - 1 && col == N)        
    return 1;    
    if (col == N)    
    {        
        row++;        
        col = 0;    
    }    
    if (grid[row][col] > 0)        
    return solveSuduko(grid, row, col + 1);    
    for (int num = 1; num <= N; num++)    
    {        
        if (isSafe(row, col, num))        
        {            
            grid[row][col] = num;            
            r[row]|=(1<<num);            
            c[col]|=(1<<num);            
            s[(row/3)*3+(col/3)]|=(1<<num);            
            if (solveSuduko(grid,row, col + 1)==1)                
            return 1;                
            r[row]-=(1<<num);        
            c[col]-=(1<<num);        
            s[(row/3)*3+(col/3)]-=(1<<num);        
            grid[row][col] = 0;        
        }    
    }    
    return 0;
}
int main()
{
    int grid[N][N];    
    for(int i=0;i<9;i++)    
    {        
        for(int  j=0;j<9;j++)        
        {            
            scanf("%d",&grid[i][j]);            
            r[i]|=(1<<grid[i][j]);            
            c[j]|=(1<<grid[i][j]);            
            s[(i/3)*3+(j/3)]|=(1<<grid[i][j]);        
        }    
    }    
    if (solveSuduko(grid, 0, 0))        
    print(grid);    
    else        
    printf("Not Solved");
}

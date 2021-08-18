Sudoku Validity  
Given a 9×9 sudoku the program must evaluate it for its correctness. 
The program must check both the sub matrix correctness and the entire sudoku correctness using the following rules.
Rule 1: Each 3*3 sub matrix must contain all digits from 1 to 9. 
Rule 2: The digits 1 to 9 must not repeat in a given or column in the 9*9 sudoku matrix. 

Boundary Condition(s):
Sudoku matrix is 9*9 matrix 

Input Format: 
9 lines containing 9 integer values representing the column values. 

Output Format: 
The first line contains VALID or INVALID 

Example 
Input/Output 1: 
Input: 
1 1 3 6 8 7 2 4 9 
8 4 9 5 2 1 6 3 7 
2 6 7 3 4 9 5 8 1
1 5 8 4 6 3 9 7 2 
9 7 4 2 1 8 3 6 5 
3 2 6 7 9 5 4 1 8 
7 8 2 9 3 4 1 5 6 
6 3 5 1 7 2 8 9 4 
1 9 4 8 5 6 7 2 3 

Output: 
INVALID Explanation: 1 is repeated along first row. (Also 1 is repeated along first column). 

Example Input/Output 2:
Input: 
5 1 3 6 8 7 2 4 9 
8 4 9 5 2 1 6 3 7 
2 6 7 3 4 9 5 8 1 
1 5 8 4 6 3 9 7 2 
9 7 4 2 1 8 3 6 5 
3 2 6 7 9 5 4 1 8 
7 8 2 9 3 4 1 5 6 
6 3 5 1 7 2 8 9 4 
4 9 1 8 5 6 7 2 3 

Output: 
VALID

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r[9],c[9],s[9],d;
    for(int i=0;i<9;i++)
    r[i]=c[i]=s[i]=1;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&d);
            r[i]|=(1<<d);
            c[j]|=(1<<d);
            s[(i/3)*3+(j/3)]|=(1<<d);
        }
    }
    d=(1<<10)-1;
    for(int i=0;i<9;i++)
    {
        if(r[i]!=d||c[i]!=d||s[i]!=d)
        {
            printf("INVALID");
            return;
        }
    }
    printf("VALID");
}

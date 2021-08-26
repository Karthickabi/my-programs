Wildcard Pattern Matching  
The program must accept a text and a wildcard pattern as the input.The program must print "Matching" if the wildcard is matched with text. 
Else the program must print "Not matching" as the output. 
The wildcard pattern can include the characters '?' and '*' '?' – Matches any single character '*' – Matches any sequence of characters 
(including the empty sequence) 

Boundary Condition(s): 
1 <= Length of text <= 100 
1 <= Length of wildcard pattern <= 50 

Input Format: 
The first line contains the text. 
The second line contains the wildcard pattern. 

Output Format: 
The first line contains either "Matching" or "Not matching".

Example Input/Output 1: 
Input: 
abbbbbbbbccbbbbbed 
a*b?d 

Output:
Matching 

Explanation:
The wildcard pattern is "a*b?d". '*' can be replaced by "bbbbbbbbccbbbb". 
'?' can be replaced by "e". Hence the output is Matching

Example Input/Output 2:
Input: 
abbbbbbbbccbhd 
a*b??b?d

Output:
Matching 

Example Input/Output 3: 
Input: 
abbbbbbbbccbhd
*c??b?d 

Output: 
Not matching

#include<stdio.h>
#include<string.h>

int main()
{    
    char a[101],b[51];    
    scanf("%s%s",a,b);
    int al=strlen(a),bl=strlen(b);
    char dp[al+1][bl+1];    
    memset(dp,0,(al+1)*(bl+1));    
    dp[0][0]=1;    
    dp[0][1]=b[0]=='*';    
    for(int i=1;i<=al;i++)    
    {        
        for(int j=1;j<=bl;j++)        
        {            
            if(b[j-1]=='*')            
            {                
                dp[i][j]=dp[i-1][j]|dp[i][j-1];           
            }            
            else if(b[j-1]=='?'||a[i-1]==b[j-1])            
            {                
                dp[i][j]=dp[i-1][j-1];          
            }       
        }    
    }   
    printf(dp[al][bl]?"Matching":"Not matching");
}

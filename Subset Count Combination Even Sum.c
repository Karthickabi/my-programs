Subset Count Combination Even Sum
The program must accept N integers as the input. The program must print the number of combinations C of the integers (1 or more integers) which add up to an even integer.
If two or more combinations give the same even sum, then all those combinations will be considered.

Boundary Condition(s): 
1 <= N <= 40 
1 <= Each integer value <= 100 

Input Format: 
The first line contains N. 
The second line contains N integers separated by a space.

Output Format: 
The first line contains C. 

Example Input/Output 1:
Input: 
5 
1 3 5 7 9

Output: 
15 
Explanation: 
The 15 possible combinations that give an even sum are
1 3 
1 5 
1 7
1 9 
3 5 
3 7 
3 9 
5 7 
5 9 
7 9 
1 3 5 7
1 3 5 9 
1 3 7 9
1 5 7 9 
3 5 7 9

Example Input/Output 2:
Input: 
6 
9 7 2 3 4 10 

Output: 
31

#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{    
    return *(int *)a-*(int *)b;
}
int main()
{    
    int n;    
    scanf("%d",&n);    
    int a[n],sum=0;
    long int c=0;  
    for(int i=0;i<n;i++) 
    {       
        scanf("%d",&a[i]);  
        sum+=a[i];  
    }   
    qsort(a,n,4,cmp); 
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)   
    dp[i][0]=0;  
    for(int i=0;i<=sum;i++)  
    dp[0][i]=0;   
    for(int i=1;i<=n;i++)  
    {        
        int curr=a[i-1];   
        for(int j=1;j<=sum;j++) 
        {            
            if(j>=curr &&(j==curr||dp[i-1][j-curr]>0))  
            {                
                if(j==curr)     
                {              
                    dp[i][j]=dp[i-1][j]+1;   
                }                
                else           
                {                
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-curr];        
                }       
                if(j%2==0)  
                {               
                    if(j==curr)     
                    {               
                        c++;        
                    }         
                    else      
                    {           
                        c+=dp[i-1][j-curr];      
                    }    
                }      
            }          
            else       
            {           
                dp[i][j]=dp[i-1][j];  
            }     
        }   
    }    
    printf("%ld",c);
}

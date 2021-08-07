Stair Climbing - Slippery stairs   
There are N stairs to be climbed in a building. 
A robot can take only S different leaps each containing certain distinct steps which are passed as the input. 
But T stairs are slippery and hence the robot will slip to the bottom stair if it lands on a slippery stair. 
The slippery stair numbers are passed as the input. 
The program must print the number of ways C of steps the robot can take to climb N stairs. 

Boundary Condition(s): 
1 <= N <= 50 
1 <= S <= 10 
1 <= T <= N 

Input Format: 
The first line contains N, S and T separated by a space. 
The second line contains S integer values separated by a space. 
The third line contains T integer values separated by a space.

Output Format: 
The first line contains the value of C. 

Example Input/Output 1: 
Input: 
5 2 1 
2 3 
2 
Output:
2 
Explanation: 
There are 5 steps. The robot can take 2 or 3 steps at a time.
So the possible ways are 
3 2 
1 2 2 (as the robot will slip to step 1 when it lands on step 2 which is slippery) 

Example Input/Output 2: 
Input:
6 2 1 
2 3 
2 
Output: 
3 
Explanation: 
The possible ways are 1 2 3 (as the robot will slip to step 1 when it lands on step 2 which is slippery) 
1 3 2 (as the robot will slip to step 1 when it lands on step 2 which is slippery) 
3 3

#include<stdio.h>
#include<stdlib.h>
int main()
{    
    int n,s,t;       
    scanf("%d%d%d",&n,&s,&t);        
    long int a[n+1];        
    int b[s];    
    char k[n+1];    
    a[0]=1;        
    for(int i=1;i<=n;k[i]=a[i]=0,i++);        
    for(int i=0;i<s;i++)        
    {                
        scanf("%d",&b[i]);        
    }        
    for(int i=0,b;i<t;i++)        
    {                
        scanf("%d",&b);                
        k[b]=1;
    }        
    for(int i=1;i<=n;i++)        
    {           
        for(int j=0;j<s;j++)                
        {                        
            if(b[j]<=i)                        
            {                                
                a[i]+=a[i-b[j]];                        
            }                
        }          
        if(k[i])        
        {            
            int p=i-1;            
            while(k[p]&&p)            
            p--;            
            if(p)           
            a[p]+=a[i];            
            a[i]=0;        
        }    
    }    
    printf("%ld",a[n]);
}

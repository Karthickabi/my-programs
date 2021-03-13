#include <stdio.h>
int ati(char *a,int n)
{int s=0;
for(int i=0;i<n;i++)
s=s*10+(a[i]-'0');
return s;}
int main()
{char a[1001];
scanf("%s",a);
int n=0,l=strlen(a)-1,s;
while(a[l]!='=')
{l--;n++;}
s=atoi(a+l+1);
int dp[l+1][s+1];
for(int i=0;i<l;i++)
dp[i][0]=0;
for(int i=0;i<l;i++)
{int p[n],p1=0;
for(int j=0;j<n;j++)
{if(i>=j)
p[p1++]=ati(a+i-j,j+1);}
for(int j=1;j<=s;j++)
{dp[i][j]=0;
for(int k=0;k<n;k++)
{if(i==k&&j==p[k])
dp[i][j]=1;
else if(j>=p[k]&&i-k-1>=0&&dp[i-k-1][j-p[k]]!=0)
dp[i][j]=dp[i][j]&&dp[i][j]<1+dp[i-k-1][j-p[k]]?dp[i][j]:1+dp[i-k-1][j-p[k]];
}}}
printf("%d ",dp[l-1][s]-1);}
//minimum no pluses added to string to make it equals
/*3+6+17+15+13+15+6+12+9+1+2+7+10+19+3+6+06+12+16+11+8+7+9+21+02+3+7+1+5 
=252*/

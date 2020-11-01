//codevita 2020 maxSum and atleast maxsum consecutive
#include <bits/stdc++.h> 
#define maxLen 10 
using namespace std; 
int dp[maxLen]; 
//iterative method
int Max_Sum(int arr[], int K, int N)
{
	int dp[N + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i < K ; i++)
		dp[i] = dp[i-1]+arr[i-1];
	for(int i = K ; i <= N; ++i)
	{int t=0;
	 for(int j = i; j >= (i - K + 1); j--){
	 t+=arr[j-1];
	 dp[i] = max(dp[i], dp[j-1]+t-arr[j-1]);}}
	return dp[N];}
 //recusion method
int maxSum(int arr[], int i, int n, int k)//,bool visit[]) 
{if (i >= n) 
return 0; 
/*if (visit[i])
return dp[i]; 
visit[i] = 1; */
int tot = 0; 
dp[i] = maxSum(arr, i + 1, n, k/*,visit*/); 
for (int j = i; j < i + k and j < n; j++){
    tot += arr[j]; 
	dp[i] = max(dp[i], tot +/*maxSum(arr, j + 2, n, k,visit)*/(j+2<n?dp[j+2]:0));}
return dp[i];} 
int main() 
{int n,a,b;
cin>>n>>a>>b;
b+=a;
int arr[n],k;
for(int i=0;i<n;i++)
cin>>arr[i];
//bool v1[n]={0};
k=maxSum(arr, 0, n, a); 
for(int i=0;i<n;i++)
dp[i]=0;
cout <<abs(k-maxSum(arr,0,n,b));
return 0; 
}
//10 9 -3

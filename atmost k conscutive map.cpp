#include <iostream> 
#include <iterator> 
#include <map> 
using namespace std; 

int max_sum(int arr[], int N,int K) 
{   int dp[N],ans=arr[0];
	map<int, int> mp;
	dp[0] = arr[0];
	mp[dp[0]]++;
for (int i = 1;i < N; i++) {
	auto it = mp.end();
	it--;
	dp[i] = max(it->first+ arr[i], arr[i]);
	mp[dp[i]]++;
	if (i>=K)  
	mp.erase(dp[i - K]);
	ans = max(ans, dp[i]);} 
	return ans;} 
int main() 
{ int arr[] = { 10,-2,-10,-5,20}; 
int N = sizeof(arr) / sizeof(int); 
int K = 2; 
cout << max_sum(arr, N, K); 
return 0; 
}

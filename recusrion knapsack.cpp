#include <bits/stdc++.h> 
#include<vector>
using namespace std;
int knapSack(int W, int wt[], int val[], int n,vector<int>&c) 
{
	if (n == 0 || W == 0) 
		return 0;
	if (wt[n-1] > W) 
		return knapSack(W, wt, val, n - 1,c);
	else
		{int s=c.size(),a=val[n-1] + knapSack(W - wt[n-1], wt, val, n - 1,c);
		int e=c.size(),b=knapSack(W, wt, val, n - 1,c);
		auto p=c.cbegin();
		if(a>b)
		{if(c.size()>e)
		c.erase(p+e,p+c.size());
		c.push_back(wt[n-1]);
		return a;
		}else
		{if(e>s)
		c.erase(p+s,p+e);
		return b;
		}}} 

// Driver code 
int main() 
{ vector<int>c;
printf("hello");
	int wt[] = {7,  0,  30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0,  36, 3,  8,  15,
     42, 9,  0,  42, 47, 52, 32, 26, 48, 55, 6,  29, 84, 2,  4,  18, 56,
     7,  29, 93, 44, 71, 3,  86, 66, 31, 65, 0,  79, 20, 65, 52, 13}; 
	int val[] = {360, 83, 59,  130, 431, 67, 230, 52,  93,  125, 670, 892, 600,
    38,  48, 147, 78,  256, 63, 17,  120, 164, 432, 35,  92,  110,
    22,  42, 50,  323, 514, 28, 87,  73,  78,  15,  26,  78,  210,
    36,  85, 189, 274, 43,  33, 10,  19,  389, 276, 312}; 
	int W = 100; 
	int n = sizeof(val) / sizeof(val[0]); 
	cout << knapSack(W, wt, val, n,c)<<" ";
	for(auto i:c)
	cout<<i<<" ";
	return 0; 
}

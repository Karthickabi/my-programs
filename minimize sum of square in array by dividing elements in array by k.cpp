#include <bits/stdc++.h>
using namespace std;
int minSum(int a[], int n, int k)
{
	priority_queue <int> q(a,a+n);
	q.push(0);
	while(q.empty()!=k+1)
	{
		int dp=q.top(),d=1;
		q.pop();
		while(d<=k-q.size()&&dp/d>=q.top())
		d++;
		int r=dp%d,quo=dp/d;
		for(int i=0;i<d;i++)
		q.push(quo+(i<r));
		break;
	}
	int sum = 0;
	while(!q.empty())
	{
		sum+= q.top()*q.top();
		cout<<q.top()<<" ";
		q.pop();
	}
	return sum;
}
int main()
{
	
	int n,k;
	int a[n];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout << (minSum(a, n, k));
	return 0;
}

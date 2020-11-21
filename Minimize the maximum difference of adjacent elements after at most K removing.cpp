#include <bits/stdc++.h>
using namespace std;
int findKMin(int arr[], int n, int k)
{deque<int> Qi(k);
	int i;
	for (i = 0; i < k; ++i) {
	    while ((!Qi.empty()) &&arr[i] >= arr[Qi.back()])
            Qi.pop_back(); 
		Qi.push_back(i);
	}
	int minDiff=INT_MAX;
	for (; i < n; ++i) {
		minDiff = min(minDiff, arr[Qi.front()]);
		while ((!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();
		Qi.push_back(i);
	}
	minDiff = min(minDiff, arr[Qi.front()]);
	return minDiff;
}
int minimumAdjacentDifference(int a[],int n, int k)
{
	int diff[n - 1];
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
	}
	int answer = findKMin(diff,n - 1, n - k - 1);
	return answer;
}
int maximumAdjacentDifference(int* arr, int n, int k) 
{ int ans = arr[n - k - 1] - arr[0];
    for (int i = 1; i <= k; i++) {
    ans = min(arr[n - 1 - (k - i)] - arr[i], ans); 
    } 
    return ans; } 
int main()
{
	int n = 5;
	int k = 2;
int a[n] = {3, 7, 8, 10, 14};
cout << minimumAdjacentDifference(a, n, k);
	return 0;
}

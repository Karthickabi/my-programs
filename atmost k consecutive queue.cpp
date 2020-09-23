#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 10;
class Solution {
   public:
   int constrainedSubsetSum(vector<int>& v, int k) {
      int ret = -inf;
      vector<int> dp(v.begin(), v.end());
      deque<int> dq;
      dq.push_front(v[0]);
      int n = v.size();
      ret = v[0];
      for (int i = 1; i < n; i++) {
         if (i > k && dq.front() == dp[i - k - 1])
         dq.pop_front();
         dp[i] = max(dp[i], dq.empty() ? dp[i] + 0 : dp[i] +
         dq.front());
         while (!dq.empty() && dq.back() < dp[i])
         dq.pop_back();
         dq.push_back(dp[i]);
         ret = max(ret, dp[i]);
      }
      return ret;
   }
};
main(){
   Solution ob;
   vector<int> v = {10,2,-9,5,19};
   cout << (ob.constrainedSubsetSum(v, 2));

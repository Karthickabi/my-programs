class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      deque<int> q;
      vector<int> S;
      int res = nums[0];
      for (int i = 0; i < nums.size(); i++) {
        int curr = nums[i] += q.empty() ? 0 : q.front();
        res = max(res, curr);
        S.push_back(curr);
        while(!q.empty() && q.back() < curr) q.pop_back();
        if (curr > 0)
          q.push_back(curr);
        if (i - k >= 0 && !q.empty() && q.front() == S[i - k]) q.pop_front();
      }
      return res;
}
};

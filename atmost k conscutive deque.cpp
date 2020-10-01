class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      deque<int> q;
      int res = nums[0];
      for (int i = 0; i < nums.size(); i++) {
        nums[i] += q.empty() ? 0 : q.front();
        res = max(res,nums[i]);
        while(!q.empty() && q.back() < nums[i]) 
            q.pop_back();
        if (nums[i] > 0)
          q.push_back(nums[i]);
        if (i - k >= 0 && !q.empty() && q.front() == nums[i - k]) 
            q.pop_front();}
      return res;
}
};

class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    int n = nums.size();
    int ans = nums[0], now = nums[0];
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1])
        now += nums[i];
      else
        now = nums[i];
      ans = max(ans, now);
    }
    return ans;
  }
};

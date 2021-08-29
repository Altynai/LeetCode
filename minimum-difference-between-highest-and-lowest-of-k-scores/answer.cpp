class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = nums[k - 1] - nums[0];
    for (int i = k; i < n; i++)
      ans = min(ans, nums[i] - nums[i - (k - 1)]);
    return ans;
  }
};

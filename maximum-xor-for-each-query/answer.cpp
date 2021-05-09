class Solution {
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit) {
    int val = 0;
    for (int num : nums)
      val ^= num;

    int n = nums.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      ans[i] = (1 << maximumBit) - 1 - val;
      val ^= nums[n - 1 - i];
    }
    return ans;
  }
};

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    vector<int> cnt(10001, 0);
    int n = nums.size(), ans = 0;
    int l = 0, sum = 0;
    for (int r = 0; r < n; r++) {
      sum += nums[r];
      if (++cnt[nums[r]] == 2) {
        while (l < r && nums[l] != nums[r]) {
          sum -= nums[l];
          cnt[nums[l]]--;
          l++;
        }
        sum -= nums[l];
        cnt[nums[l]]--;
        l++;
      }
      ans = max(ans, sum);
    }
    return ans;
  }
};

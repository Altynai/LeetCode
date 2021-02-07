class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {
    int n = nums.size();
    int ans = 0, sum = 0;
    int mi = 0, ma = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      ans = max(ans, abs(sum - mi));
      ans = max(ans, abs(sum - ma));
      mi = min(mi, sum);
      ma = max(ma, sum);
    }
    return ans;
  }
};

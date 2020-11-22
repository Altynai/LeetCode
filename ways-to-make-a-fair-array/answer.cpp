class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int n = nums.size();
    vector<int> sum(2, 0);
    for (int i = 1; i <= n; i++) {
      sum[i & 1] += nums[i - 1];
    }

    int ans = 0;
    vector<int> cur(2, 0);
    for (int i = 1; i <= n; i++) {
      sum[i & 1] -= nums[i - 1];
      if (cur[0] + sum[1] == cur[1] + sum[0])
        ans++;
      cur[i & 1] += nums[i - 1];
    }
    return ans;
  }
};

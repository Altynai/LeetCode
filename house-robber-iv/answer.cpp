class Solution {
public:
  int minCapability(vector<int> &a, int k) {
    int n = a.size();
    int l = *min_element(a.begin(), a.end());
    int r = *max_element(a.begin(), a.end());

    auto Test = [&](int cap) -> bool {
      vector<int> dp(2, 0);
      if (a[0] <= cap)
        dp[1] = 1;

      for (int i = 1; i < n; i++) {
        vector<int> ndp(2, 0);
        // skip
        ndp[0] = max(dp[0], dp[1]);
        // steal
        if (a[i] <= cap)
          ndp[1] = dp[0] + 1;
        dp = ndp;
      }
      return max(dp[0], dp[1]) >= k;
    };

    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

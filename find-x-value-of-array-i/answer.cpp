using int64 = long long;

class Solution {
public:
  vector<long long> resultArray(vector<int> &a, int k) {
    int n = a.size();

    vector<int64> ans(k, 0);

    // dp[i][j]: # of subarrays ending at i, with module equals to j
    vector<int64> dp(k, 0);
    ans[a[0] % k] = dp[a[0] % k] = 1;

    for (int i = 1; i < n; i++) {
      vector<int64> ndp(k, 0);
      ndp[a[i] % k]++;
      for (int j = 0; j < k; j++)
        ndp[(a[i] % k) * j % k] += dp[j];
      swap(dp, ndp);
      for (int j = 0; j < k; j++)
        ans[j] += dp[j];
    }
    return ans;
  }
};

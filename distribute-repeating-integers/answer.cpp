class Solution {
public:
  bool canDistribute(vector<int> &nums, vector<int> &q) {
    unordered_map<int, int> cnt;
    for (int num : nums)
      cnt[num] += 1;

    vector<int> cnts;
    for (auto [k, v] : cnt)
      cnts.push_back(v);

    int n = cnts.size();
    int m = q.size();

    bool dp[n][1 << m];
    memset(dp, 0, sizeof(dp));

    // pre-compute the total quantity
    vector<int> w(1 << m, 0);
    for (int mask = 1; mask < (1 << m); mask++) {
      for (int i = 0; i < m; i++) {
        if ((mask >> i) & 1)
          w[mask] += q[i];
      }
    }

    for (int mask = 0; mask < (1 << m); mask++) {
      if (cnts[0] >= w[mask])
        dp[0][mask] = 1;
    }

    for (int i = 1; i < n; i++) {
      for (int mask = 0; mask < (1 << m); mask++) {
        if (!dp[i - 1][mask])
          continue;
        dp[i][mask] = 1;
        for (int mask2 = 0; mask2 < (1 << m); mask2++) {
          if ((mask & mask2) == 0 && cnts[i] >= w[mask2]) {
            dp[i][mask | mask2] = 1;
          }
        }
      }
    }
    return dp[n - 1][(1 << m) - 1];
  }
};

using int64 = long long;

class Solution {
public:
  long long minimumCost(vector<int> &a, vector<int> &cost, int k) {
    // dp[i]: minimal cost for a[i ... n - 1]

    // [L1, R1], [L2, R2]
    // dp[i] = (a[0 ... R1] + k * 1) * cost[L1 .. R1] +
    //         (a[0 ... R2] + k * 2) * cost[L2 .. R2]

    // [L0, R0], [L1, R1], [L2, R2]
    // (a[0 ... R0] + k * 1) * cost[L0 .. R0] +
    // (a[0 ... R1] + k * 2) * cost[L1 .. R1] +
    // (a[0 ... R2] + k * 3) * cost[L2 .. R2]

    // (a[0 ... R0] + k * 1) * cost[L0 .. R0] + dp[i] +
    // k * cost[L1 .. R1] + k * cost[L2 .. R2]

    // so dp[L0] = (a[0 ... R0] + k * 1) * cost[L0 .. R0] + dp[L1] + k * cost[L1
    // ... n - 1]

    int n = a.size();

    vector<int> pfx(n, a[0]);
    for (int i = 1; i < n; i++)
      pfx[i] = pfx[i - 1] + a[i];

    vector<int> sfx(n, cost[n - 1]);
    for (int i = n - 2; i >= 0; i--)
      sfx[i] = sfx[i + 1] + cost[i];

    vector<int64> dp(n, LLONG_MAX);
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = 1LL * (pfx[n - 1] + k) * sfx[i];
      for (int j = i + 1; j < n; j++) {
        // [i .. j - 1] as a new subarray
        int64 val = 1LL * (pfx[j - 1] + k) * (sfx[i] - sfx[j]);
        dp[i] = min(dp[i], val + dp[j] + 1LL * k * sfx[j]);
      }
    }
    return dp[0];
  }
};

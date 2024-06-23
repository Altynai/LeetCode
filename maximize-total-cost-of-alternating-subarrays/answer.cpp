template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maximumTotalCost(vector<int> &a) {
    // prefix[i] = a[1] - a[2] + a[3] .... +/-a[i]

    // if j is odd
    // dp[i] = max(dp[j] - (prefix[i] - prefix[j]))
    // dp[i] = max(dp[j] + prefix[j]) - prefix[i]

    // if j is even
    // dp[i] = max(dp[j] + (prefix[i] - prefix[j]))
    // dp[i] = max(dp[j] - prefix[j]) + prefix[i]

    int n = a.size();
    vector<int64> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
      prefix[i] = prefix[i - 1] + (i % 2 == 1 ? a[i - 1] : -a[i - 1]);

    const int64 INF = -1e16;
    vector<int64> dp(n + 1, INF);
    dp[0] = 0;
    int64 odd_best = INF, even_best = 0;
    for (int i = 1; i <= n; i++) {
      if (odd_best != INF)
        umax(dp[i], odd_best - prefix[i]);
      if (even_best != INF)
        umax(dp[i], even_best + prefix[i]);

      if (i % 2 == 1)
        umax(odd_best, dp[i] + prefix[i]);
      else
        umax(even_best, dp[i] - prefix[i]);
    }
    return dp[n];
  }
};

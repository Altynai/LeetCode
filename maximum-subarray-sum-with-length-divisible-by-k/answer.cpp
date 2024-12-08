template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maxSubarraySum(vector<int> &a, int k) {
    int n = a.size();
    vector<int64> sum(n, a[0]);
    for (int i = 1; i < n; i++)
      sum[i] = sum[i - 1] + a[i];

    vector<int64> dp(n, LLONG_MIN);
    dp[k - 1] = sum[k - 1];
    for (int i = k; i < n; i++) {
      int64 s = sum[i] - sum[i - k];
      dp[i] = s;
      if (dp[i - k] > 0)
        umax(dp[i], dp[i - k] + s);
    }
    return *max_element(dp.begin(), dp.end());
  }
};

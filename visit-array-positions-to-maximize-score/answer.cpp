using int64 = long long;

class Solution {
public:
  long long maxScore(vector<int> &a, int x) {
    int n = a.size();
    vector<int64> dp(2, LLONG_MIN);
    dp[a[0] & 1] = a[0];

    int64 ans = a[0];
    for (int i = 1; i < n; i++) {
      vector<int64> ndp = dp;
      // same parity
      int same = a[i] & 1;
      if (dp[same] != LLONG_MIN)
        ndp[same] = max(ndp[same], dp[same] + a[i]);
      // other parity
      int other = same ^ 1;
      if (dp[other] != LLONG_MIN)
        ndp[same] = max(ndp[same], dp[other] + a[i] - x);

      dp = ndp;
      ans = max(ans, max(dp[0], dp[1]));
    }
    return ans;
  }
};

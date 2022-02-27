template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}

class Solution {
public:
  int minimumFinishTime(vector<vector<int>> &tires, int change, int m) {
    sort(tires.begin(), tires.end());
    int n = tires.size();

    long long worst = 1LL * tires[0][0] * m + 1LL * change * (m - 1);
    vector<int> best(m + 1, INT_MAX);
    for (auto &tire : tires) {
      int lap = 1;
      long long sec = tire[0], sum = tire[0];
      while (sum <= worst) {
        umin(best[lap], (int)(sum));
        sec *= tire[1];
        sum += sec;
        lap++;
      }
    }

    // min cost to run i laps
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i <= m; i++) {
      if (dp[i] == INT_MAX)
        continue;

      for (int j = 1; j <= m; j++) {
        if (best[j] == INT_MAX)
          continue;

        int sec = best[j] + (i > 0 ? change : 0);
        if (i + j <= m)
          umin(dp[i + j], dp[i] + sec);
      }
    }
    return dp[m];
  }
};

using int64 = long long;

const int64 MIN_INF = -1e15;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  long long maximumStrength(vector<int> &a, int k) {
    int n = a.size();

    vector<vector<int64>> dp(k + 1, vector<int64>(2, MIN_INF));
    dp[0][0] = 0;

    auto Get = [&](int j) -> int64 { return (j & 1) ? 1LL : -1LL; };

    for (int i = n - 1; i >= 0; i--) {
      vector<vector<int64>> ndp(k + 1, vector<int64>(2, MIN_INF));

      for (int j = 0; j <= k; j++) {
        for (int choose = 0; choose <= 1; choose++) {
          if (dp[j][choose] == MIN_INF)
            continue;

          // skip
          umax(ndp[j][0], dp[j][choose]);

          // start a new subarray
          if (choose == 0 and j + 1 <= k)
            umax(ndp[j + 1][1], dp[j][choose] + Get(j + 1) * (j + 1) * a[i]);

          // continue the current subarray
          if (choose == 1)
            umax(ndp[j][1], dp[j][choose] + Get(j) * j * a[i]);
        }

        // subarray ends at the current position
        umax(ndp[j][0], ndp[j][1]);
      }

      swap(dp, ndp);
    }

    return max(dp[k][0], dp[k][1]);
  }
};

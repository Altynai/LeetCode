template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minTravelTime(int l, int n, int k, vector<int> &pos, vector<int> &t) {
    // if we merge position[l ... r], only position[r] is kept,
    // time[l ... r] will be accumulated and set to time[r]

    // dp[i][j][t]: we've used j merges, last one is i, accumulated time is t

    const int T = accumulate(t.begin(), t.end(), 0);

    vector<int> pfx(n, t[0]);
    for (int i = 1; i < n; i++)
      pfx[i] = pfx[i - 1] + t[i];

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(k + 1, vector<int>(T + 1, INT_MAX)));
    dp[0][0][t[0]] = 0;

    for (int i = 0; i < n; i++) {
      for (int op = 0; op <= k; op++) {
        for (int sum_t = 0; sum_t <= T; sum_t++) {
          if (dp[i][op][sum_t] == INT_MAX)
            continue;

          // merge [i + 1, ...., j]
          for (int j = i + 1; j < n; j++) {
            int op2 = j - (i + 1) + op;
            if (op2 > k)
              continue;

            int sum_t2 = pfx[j] - pfx[i];
            umin(dp[j][op2][sum_t2],
                 dp[i][op][sum_t] + sum_t * (pos[j] - pos[i]));
          }
        }
      }
    }
    return *min_element(dp[n - 1][k].begin(), dp[n - 1][k].end());
  }
};

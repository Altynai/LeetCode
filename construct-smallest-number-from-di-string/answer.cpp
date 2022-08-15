using int64 = long long;

#define bit(n, i) (((n) >> (i)) & 1)

template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  string smallestNumber(string s) {
    int n = s.size() + 1;
    int m = n + 1;

    vector<vector<int64>> dp(1 << m, vector<int64>(m, LLONG_MAX));
    for (int i = 1; i <= n; i++)
      dp[1 << i][i] = i;

    for (char ch : s) {
      vector<vector<int64>> ndp(1 << m, vector<int64>(m, LLONG_MAX));

      for (int mask = 1; mask < (1 << m); mask++) {
        for (int k = 1; k <= n; k++) {
          if (dp[mask][k] == LLONG_MAX)
            continue;

          int start = (ch == 'I' ? k + 1 : k - 1);
          int end = (ch == 'I' ? n + 1 : 0);
          int delta = (ch == 'I' ? +1 : -1);
          for (int j = start; j != end; j += delta) {
            if (!bit(mask, j)) {
              umin(ndp[mask | (1 << j)][j], dp[mask][k] * 10 + j);
            }
          }
        }
      }

      dp = ndp;
    }

    int64 ans = LLONG_MAX;
    for (int k = 1; k <= n; k++)
      umin(ans, dp[(1 << m) - 2][k]);
    return to_string(ans);
  }
};

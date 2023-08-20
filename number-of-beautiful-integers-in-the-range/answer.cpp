template <int D, typename T> struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T> struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};

class Solution {
private:
  int count(int n, int k) {
    string s = to_string(n);
    int m = s.size();

    int ans = 0;
    // len < m
    for (int len = 2; len < m; len += 2) {
      int digits = len / 2;
      Vec<3, int> dp(digits + 2, digits + 2, k, 0);
      dp[0][0][0] = 1;

      for (int i = 1; i <= len; i++) {
        Vec<3, int> ndp(digits + 2, digits + 2, k, 0);
        for (int x = 0; x <= digits; x++) {
          for (int y = 0; y <= digits; y++) {
            for (int mod = 0; mod < k; mod++) {
              for (int d = (i == 1 ? 1 : 0); d <= 9; d++) {
                if (d & 1)
                  ndp[x][y + 1][(mod * 10 + d) % k] += dp[x][y][mod];
                else
                  ndp[x + 1][y][(mod * 10 + d) % k] += dp[x][y][mod];
              }
            }
          }
        }
        swap(dp, ndp);
      }
      ans += dp[digits][digits][0];
    }
    if (m & 1)
      return ans;

    // len = m
    int digits = m / 2;
    Vec<4, int> dp(digits + 2, digits + 2, k, 2, 0);
    int first = s[0] - '0';
    for (int d = 1; d <= first; d++)
      dp[(d & 1) ^ 1][d & 1][d % k][(d < first ? 0 : 1)]++;

    for (int pos = 2; pos <= m; pos++) {
      int digit = s[pos - 1] - '0';
      Vec<4, int> ndp(digits + 2, digits + 2, k, 2, 0);

      for (int x = 0; x <= digits; x++) {
        for (int y = 0; y <= digits; y++) {
          for (int mod = 0; mod < k; mod++) {
            for (int d = 0; d <= 9; d++) {
              if (d & 1) {
                // update cmp = 0
                ndp[x][y + 1][(mod * 10 + d) % k][0] += dp[x][y][mod][0];
                if (d < digit)
                  ndp[x][y + 1][(mod * 10 + d) % k][0] += dp[x][y][mod][1];

                // update cmp = 1
                if (d == digit)
                  ndp[x][y + 1][(mod * 10 + d) % k][1] += dp[x][y][mod][1];
              } else {
                // update cmp = 0
                ndp[x + 1][y][(mod * 10 + d) % k][0] += dp[x][y][mod][0];
                if (d < digit)
                  ndp[x + 1][y][(mod * 10 + d) % k][0] += dp[x][y][mod][1];
                // update cmp = 1
                if (d == digit)
                  ndp[x + 1][y][(mod * 10 + d) % k][1] += dp[x][y][mod][1];
              }
            }
          }
        }
      }
      swap(dp, ndp);
    }
    ans += dp[digits][digits][0][0] + dp[digits][digits][0][1];
    return ans;
  }

public:
  int numberOfBeautifulIntegers(int low, int high, int k) {
    return count(high, k) - count(low - 1, k);
  }
};

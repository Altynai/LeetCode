#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxLen(int n, vector<vector<int>> &edges, string label) {
    vector<vector<vector<bool>>> dp(
        1 << n, vector<vector<bool>>(n, vector<bool>(n, 0)));
    vector<vector<bool>> conn(n, vector<bool>(n, 0));
    for (auto e : edges) {
      int u = e[0], v = e[1];
      conn[u][v] = conn[v][u] = 1;
      if (label[u] == label[v])
        dp[(1 << u) | (1 << v)][u][v] = 1;
    }
    for (int i = 0; i < n; i++)
      dp[1 << i][i][i] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if (bit(mask, i) == 0)
          continue;
        for (int j = 0; j < n; j++) {
          if (bit(mask, j) == 0)
            continue;
          if (!dp[mask][i][j])
            continue;

          for (int x = 0; x < n; x++) {
            if (bit(mask, x))
              continue;
            for (int y = 0; y < n; y++) {
              if (x == y or bit(mask, y))
                continue;
              if (label[x] != label[y])
                continue;

              int mask2 = (mask | (1 << x) | (1 << y));
              if (conn[i][x] and conn[j][y])
                dp[mask2][x][y] = 1;
              if (conn[i][y] and conn[j][x])
                dp[mask2][y][x] = 1;
            }
          }
        }
      }
    }

    int ans = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dp[mask][i][j])
            umax(ans, bitCount(mask));
        }
      }
    }
    return ans;
  }
};

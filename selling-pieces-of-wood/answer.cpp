template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

#define int64 long long
const int N = 201;

int64 dp[N][N], a[N][N];

class Solution {
public:
  int64 sellingWood(int n, int m, vector<vector<int>> &prices) {
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
        a[i][j] = dp[i][j] = -1;

    for (auto &x : prices)
      a[x[0]][x[1]] = x[2];

    function<int64(int, int)> dfs = [&](int h, int w) -> int64 {
      if (dp[h][w] != -1)
        return dp[h][w];

      dp[h][w] = max(a[h][w], 0LL);
      for (int r = 1; r + 1 <= h; r++)
        umax(dp[h][w], dfs(r, w) + dfs(h - r, w));
      for (int c = 1; c + 1 <= w; c++)
        umax(dp[h][w], dfs(h, c) + dfs(h, w - c));
      return dp[h][w];
    };

    return dfs(n, m);
  }
};

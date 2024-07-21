using int64 = long long;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  long long maximumScore(vector<vector<int>> &a) {
    int n = a.size();
    vector<vector<int64>> psum(n + 1, vector<int64>(n + 1, 0));
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= n; i++)
        psum[j][i] = psum[j][i - 1] + a[i - 1][j - 1];
    }

    auto GetScore = [&](int col, int l, int r) -> int64 {
      if (l > r)
        return 0;
      if (l == 0)
        return psum[col][r];
      return psum[col][r] - psum[col][l - 1];
    };

    vector<int64> f(n + 1, 0); // f[i]: maximum score including current column
    vector<int64> g(n + 1, 0); // g[i]: maximum score excluding current column

    for (int j = 2; j <= n; j++) { // make sure to ignore the first column
      vector<int64> f2(n + 1, 0), g2(n + 1, 0);
      for (int lastHeight = 0; lastHeight <= n; lastHeight++) {
        for (int curHeight = 0; curHeight <= n; curHeight++) {
          if (lastHeight >= curHeight) {
            umax(f2[curHeight],
                 f[lastHeight] + GetScore(j, curHeight + 1, lastHeight));
            umax(f2[curHeight],
                 g[lastHeight] + GetScore(j, curHeight + 1, lastHeight));

            umax(g2[curHeight], max(f[lastHeight], g[lastHeight]));
          } else {
            umax(f2[curHeight], f[lastHeight]);
            umax(f2[curHeight],
                 g[lastHeight] + GetScore(j - 1, lastHeight + 1, curHeight));

            umax(g2[curHeight], f[lastHeight]);
            umax(g2[curHeight],
                 g[lastHeight] + GetScore(j - 1, lastHeight + 1, curHeight));
          }
        }
      }
      swap(f, f2), swap(g, g2);
    }
    return max(*max_element(f.begin(), f.end()),
               *max_element(g.begin(), g.end()));
  }
};

const int N = 26;

using int64 = long long;

template <class T> bool umin(T &a, const T b) {
  assert(b != -1);
  return (a == -1 or b < a) ? a = b, 1 : 0;
}

class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    int n = source.size();

    vector<vector<int>> dis(N, vector<int>(N, -1));
    int w = original.size();
    for (int i = 0; i < w; i++) {
      int x = original[i] - 'a';
      int y = changed[i] - 'a';
      umin(dis[x][y], cost[i]);
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        if (dis[i][k] == -1)
          continue;
        for (int j = 0; j < N; j++) {
          if (dis[k][j] == -1)
            continue;
          umin(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }

    vector<int64> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      int x = source[i] - 'a';
      int y = target[i] - 'a';
      if (x == y and dp[i + 1] != -1)
        umin(dp[i], dp[i + 1]);
      if (x != y and dp[i + 1] != -1 and dis[x][y] != -1)
        umin(dp[i], dp[i + 1] + dis[x][y]);
    }
    return dp[0];
  }
};

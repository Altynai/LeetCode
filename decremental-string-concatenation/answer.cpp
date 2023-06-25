template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

const int N = 26;

class Solution {
public:
  int minimizeConcatenatedLength(vector<string> &s) {
    int n = s.size();

    vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
    dp[s[0][0] - 'a'][s[0].back() - 'a'] = s[0].size();

    for (int i = 1; i < n; i++) {
      vector<vector<int>> ndp(N, vector<int>(N, INT_MAX));
      int x = s[i][0] - 'a';
      int y = s[i].back() - 'a';
      int len = s[i].size();

      // front: xy + str[jk]
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          if (dp[j][k] == INT_MAX)
            continue;
          umin(ndp[x][k], dp[j][k] + len - int(y == j));
        }
      }
      // back: str[jk] + xy
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          if (dp[j][k] == INT_MAX)
            continue;
          umin(ndp[j][y], dp[j][k] + len - int(k == x));
        }
      }
      swap(dp, ndp);
    }

    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
      umin(ans, *min_element(dp[i].begin(), dp[i].end()));
    }
    return ans;
  }
};

template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

const int N = 26;
vector<int> where[N][N];

class Solution {
public:
  int cost(string s, string t) {
    int n = s.size(), res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        where[i][j].clear();
    }

    for (int i = 0; i < n; i++) {
      if (s[i] == t[i])
        continue;
      where[s[i] - 'a'][t[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
        auto x = where[i][j], y = where[j][i];
        int m = min(x.size(), y.size());
        for (int k = 0; k < m; k++) {
          swap(s[x[k]], s[y[k]]);
          res++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i])
        res++;
    }
    return res;
  }

  int minOperations(string s, string t) {
    int n = s.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        string ss = s.substr(i, j - i + 1);
        string tt = t.substr(i, j - i + 1);
        c[i][j] = cost(ss, tt);
        reverse(ss.begin(), ss.end());
        umin(c[i][j], cost(ss, tt) + 1);
      }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = c[0][i];
      for (int j = 1; j <= i; j++)
        umin(dp[i], dp[j - 1] + c[j][i]);
    }
    return dp[n - 1];
  }
};

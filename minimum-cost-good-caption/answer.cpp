template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

const int N = 26;

class Solution {
public:
  string minCostGoodCaption(string s) {
    int n = s.size();
    if (n < 3)
      return "";

    vector<vector<int>> cnt(n);
    cnt[0] = vector<int>(N, 0);
    cnt[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++) {
      cnt[i] = cnt[i - 1];
      cnt[i][s[i] - 'a']++;
    }

    auto Cost = [&](int l, int r, int k) -> int {
      int res = 0;
      for (int i = 0; i < N; i++)
        res += (l == 0 ? cnt[r][i] : cnt[r][i] - cnt[l - 1][i]) * abs(i - k);
      return res;
    };

    vector<vector<int>> dp(n + 1, vector<int>(N, INT_MAX));
    for (int j = 0; j < N; j++)
      dp[n][j] = 0;

    using Track = pair<int, int>; // 1 or 3, 'a' - 'z'
    vector<vector<Track>> track(n, vector<Track>(N, {INT_MAX, INT_MAX}));

    int choose = N;
    for (int i = n - 3; i >= 0; i--) {
      choose =
          min_element(dp[i + 3].begin(), dp[i + 3].end()) - dp[i + 3].begin();

      for (int j = 0; j < N; j++) {
        if (choose != N and dp[i + 3][choose] != INT_MAX) {
          if (umin(dp[i][j], dp[i + 3][choose] + Cost(i, i + 2, j)))
            track[i][j] = {3, choose};
        }

        if (dp[i + 1][j] != INT_MAX) {
          int cost = dp[i + 1][j] + Cost(i, i, j);
          if (cost < dp[i][j])
            dp[i][j] = cost, track[i][j] = {1, j};
          else if (cost == dp[i][j] and j <= track[i][j].second)
            track[i][j] = {1, j};
        }
      }
    }

    choose = min_element(dp[0].begin(), dp[0].end()) - dp[0].begin();

    string ans(n, '*');
    for (int i = 0; i < n;) {
      auto [cnt, nxt] = track[i][choose];
      for (int j = 0; j < cnt; j++)
        ans[i + j] = 'a' + choose;
      i += cnt;
      choose = nxt;
    }
    return ans;
  }
};

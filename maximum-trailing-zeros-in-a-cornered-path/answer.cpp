using pii = pair<int, int>;
#define fi first
#define se second

pii operator+(const pii &lh, const pii &rh) {
  return {lh.fi + rh.fi, lh.se + rh.se};
}

pii operator-(const pii &lh, const pii &rh) {
  return {lh.fi - rh.fi, lh.se - rh.se};
}

class Solution {
public:
  int maxTrailingZeros(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    vector<vector<pii>> cnt(n + 1, vector<pii>(m + 1, {0, 0}));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int val = a[i - 1][j - 1];
        while (val % 2 == 0)
          cnt[i][j].fi++, val /= 2;
        while (val % 5 == 0)
          cnt[i][j].se++, val /= 5;
      }
    }

    int ans = 0;
    vector<vector<pii>> row(n + 1);
    for (int i = 1; i <= n; i++) {
      row[i].emplace_back(0, 0);
      for (int j = 1; j <= m; j++)
        row[i].push_back(row[i].back() + cnt[i][j]);

      ans = max(ans, min(row[i][m].fi, row[i][m].se));
    }

    vector<vector<pii>> col(m + 1);
    for (int j = 1; j <= m; j++) {
      col[j].emplace_back(0, 0);
      for (int i = 1; i <= n; i++)
        col[j].push_back(col[j].back() + cnt[i][j]);
      ans = max(ans, min(col[j][n].fi, col[j][n].se));
    }

    auto calculate = [&](const pii &lh, const pii &rh,
                         const pii &common) -> int {
      pii res = lh + rh - common;
      return min(res.fi, res.se);
    };

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pii up = col[j][i];
        pii down = col[j][n] - col[j][i - 1];
        pii left = row[i][j];
        pii right = row[i][m] - row[i][j - 1];

        ans = max(ans, calculate(up, left, cnt[i][j]));
        ans = max(ans, calculate(up, right, cnt[i][j]));
        ans = max(ans, calculate(down, left, cnt[i][j]));
        ans = max(ans, calculate(down, right, cnt[i][j]));
      }
    }
    return ans;
  }
};

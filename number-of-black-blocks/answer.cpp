using int64 = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  vector<long long> countBlackBlocks(int n, int m,
                                     vector<vector<int>> &coordinates) {
    unordered_set<int64> seen;
    for (auto c : coordinates)
      seen.insert(1LL * MOD * c[0] + c[1]);

    auto count = [&](int x, int y) -> int {
      int res = 0;
      for (int i = x; i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
          int64 hash = 1LL * MOD * i + j;
          if (seen.count(hash))
            res++;
        }
      }
      return res;
    };

    vector<int64> ans(5, 0);
    ans[0] = 1LL * (n - 1) * (m - 1);
    unordered_set<int64> vis;
    for (auto c : coordinates) {
      int x = c[0], y = c[1];
      for (int i = max(0, x - 1); i <= min(n - 2, x + 1); i++) {
        for (int j = max(0, y - 1); j <= min(m - 2, y + 1); j++) {
          int64 hash = 1LL * MOD * i + j;
          if (vis.count(hash))
            continue;
          vis.insert(hash);
          int cnt = count(i, j);
          ans[cnt]++;
          ans[0]--;
        }
      }
    }
    return ans;
  }
};

class Solution {
public:
  int minAbsDiff(const set<int> &s) {
    int n = s.size();
    if (n == 1)
      return 0;

    int pre = *s.begin(), ans = INT_MAX;
    for (auto it = next(s.begin()); it != s.end(); it++) {
      ans = min(ans, *it - pre);
      pre = *it;
    }
    return ans;
  }

  vector<vector<int>> minAbsDiff(vector<vector<int>> &g, int k) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
    for (int i = 0; i < n - k + 1; i++) {
      for (int j = 0; j < m - k + 1; j++) {
        set<int> s;
        for (int x = 0; x < k; x++) {
          for (int y = 0; y < k; y++)
            s.insert(g[i + x][j + y]);
        }
        ans[i][j] = minAbsDiff(s);
      }
    }
    return ans;
  }
};

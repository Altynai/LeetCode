class Solution {
public:
  vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        unordered_set<int> top, bottom;
        for (int x = i - 1, y = j - 1; x >= 0 and y >= 0; x--, y--)
          top.insert(a[x][y]);
        for (int x = i + 1, y = j + 1; x < n and y < m; x++, y++)
          bottom.insert(a[x][y]);
        ans[i][j] = abs((int)top.size() - (int)bottom.size());
      }
    }
    return ans;
  }
};

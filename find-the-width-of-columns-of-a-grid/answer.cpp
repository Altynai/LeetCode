class Solution {
public:
  vector<int> findColumnWidth(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> ans(m);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        ans[j] = max(ans[j], (int)to_string(a[i][j]).size());
      }
    }
    return ans;
  }
};

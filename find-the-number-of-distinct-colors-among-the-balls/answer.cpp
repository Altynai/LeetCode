class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>> &queries) {
    int n = queries.size(), cnt = 0;
    unordered_map<int, int> freq, color;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int x = queries[i][0], y = queries[i][1];
      if (color.count(x)) {
        if (--freq[color[x]] == 0)
          cnt--;
      }
      color[x] = y;
      if (++freq[y] == 1)
        cnt++;
      ans[i] = cnt;
    }
    return ans;
  }
};

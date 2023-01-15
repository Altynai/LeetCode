class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (auto q : queries) {
      int r0 = q[0], c0 = q[1];
      int r1 = q[2], c1 = q[3];

      for (int i = r0; i <= r1; i++) {
        ans[i][c0]++;
        if (c1 + 1 < n)
          ans[i][c1 + 1]--;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        ans[i][j] += ans[i][j - 1];
      }
    }
    return ans;
  }
};

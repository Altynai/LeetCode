class Solution {
public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans = matrix;
    for (int j = 0; j < m; j++) {
      int val = -1;
      for (int i = 0; i < n; i++)
        val = max(matrix[i][j], val);
      for (int i = 0; i < n; i++) {
        if (matrix[i][j] == -1)
          ans[i][j] = val;
      }
    }
    return ans;
  }
};

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &b) {
    int n = b.size(), m = b[0].size();
    for (int i = 0; i < n; i++) {
      int last = m;
      for (int j = m - 1; j >= 0; j--) {
        if (b[i][j] == '*')
          last = j;
        else if (b[i][j] == '#') {
          b[i][last - 1] = '#';
          if (j < last - 1)
            b[i][j] = '.';
          last--;
        }
      }
    }

    vector<vector<char>> ans(m, vector<char>(n, '.'));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++)
        ans[j][n - 1 - i] = b[i][j];
    }
    return ans;
  }
};

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> a = mat;
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n;i++) {
          if (i & 1) {
            for (int j = 0; j < m;j++) a[i][(j + k) % m] = mat[i][j];
          } else {
            for (int j = 0; j < m;j++) {
              int x = j - k;
              while (x < 0) x += m;
              a[i][x % m] = mat[i][j];
            }
          }
        }
        return mat == a;
    }
};

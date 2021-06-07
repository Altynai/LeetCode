class Solution {
public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    auto rotate = [&](vector<vector<int>> &a) {
      int n = a.size();
      vector<vector<int>> b(n, vector<int>(n, 0));
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          b[j][n - 1 - i] = a[i][j];
      }
      a = b;
    };

    for (int i = 0; i < 4; i++) {
      if (mat == target)
        return 1;
      rotate(mat);
    }
    return 0;
  }
};

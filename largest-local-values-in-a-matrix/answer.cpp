class Solution {
public:
  vector<vector<int>> largestLocal(vector<vector<int>> &a) {
    int n = a.size();
    vector<vector<int>> b(n - 2, vector<int>(n - 2));
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < n - 2; j++) {
        int val = 0;
        for (int x = i; x < i + 3; x++) {
          for (int y = j; y < j + 3; y++)
            val = max(val, a[x][y]);
        }
        b[i][j] = val;
      }
    }
    return b;
  }
};

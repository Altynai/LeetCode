class Solution {
public:
  vector<int> zigzagTraversal(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> ans;
    for (int i = 0, j = 0; i < n; i++) {
      if (i % 2 == 0) {
        while (j < m) {
          ans.push_back(a[i][j]);
          j += 2;
        }
        j = (j == m ? m - 1 : m - 2);
      } else {
        while (j >= 0) {
          ans.push_back(a[i][j]);
          j -= 2;
        }
        j = (j == -1 ? 0 : 1);
      }
    }
    return ans;
  }
};

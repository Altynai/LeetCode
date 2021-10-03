class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int> &a, int m, int n) {
    int k = a.size();
    if (n * m != k)
      return {};

    vector<vector<int>> ans(m, vector<int>(n));
    int i = 0, j = 0;
    for (int x = 0; x < k; x++) {
      ans[i][j] = a[x];
      j++;
      if (j == n)
        i++, j = 0;
    }
    return ans;
  }
};

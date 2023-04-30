class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    const int N = n * m;

    vector<int> r(N), c(N);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        r[mat[i][j] - 1] = i, c[mat[i][j] - 1] = j;
    }

    vector<int> cntRow(n, 0), cntCol(m, 0);
    for (int k = 0; k < arr.size(); k++) {
      int x = r[arr[k] - 1], y = c[arr[k] - 1];
      if (++cntRow[x] == m)
        return k;
      if (++cntCol[y] == n)
        return k;
    }
    return -1;
  }
};

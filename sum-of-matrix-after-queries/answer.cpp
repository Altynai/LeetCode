using int64 = long long;

class Solution {
public:
  long long matrixSumQueries(int n, vector<vector<int>> &queries) {
    int64 ans = 0;
    vector<bool> row(n, 0), col(n, 0);
    int rowCnt = 0, colCnt = 0;

    reverse(queries.begin(), queries.end());
    for (auto query : queries) {
      int idx = query[1];
      int64 val = query[2];
      if (query[0] == 0) {
        if (row[idx])
          continue;
        ans += val * (n - colCnt);
        rowCnt++;
        row[idx] = 1;
      } else {
        if (col[idx])
          continue;
        ans += val * (n - rowCnt);
        colCnt++;
        col[idx] = 1;
      }
    }
    return ans;
  }
};

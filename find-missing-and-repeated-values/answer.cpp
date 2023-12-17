class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> cnt(n * n, 0);
    for (auto &row : grid)
      for (int x : row)
        cnt[x - 1]++;

    int dup = -1, miss = -1;
    for (int i = 0; i < n * n; i++) {
      if (cnt[i] == 2)
        dup = i + 1;
      if (cnt[i] == 0)
        miss = i + 1;
    }
    return {dup, miss};
  }
};

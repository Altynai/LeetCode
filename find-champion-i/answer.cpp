class Solution {
public:
  int findChampion(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (grid[i][j] == 1)
          deg[j]++;
        else
          deg[i]++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (deg[i] == 0)
        return i;
    }
    return -1;
  }
};

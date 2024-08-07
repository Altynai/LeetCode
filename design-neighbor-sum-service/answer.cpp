class neighborSum {
private:
  vector<vector<int>> a;
  int n;

public:
  neighborSum(vector<vector<int>> &grid) {
    a = grid;
    n = grid.size();
  }

  int adjacentSum(int value) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == value) {
          int sum = 0;
          if (i > 0)
            sum += a[i - 1][j];
          if (i + 1 < n)
            sum += a[i + 1][j];
          if (j > 0)
            sum += a[i][j - 1];
          if (j + 1 < n)
            sum += a[i][j + 1];
          return sum;
        }
      }
    }
    return -1;
  }

  int diagonalSum(int value) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == value) {
          int sum = 0;
          if (i > 0 and j > 0)
            sum += a[i - 1][j - 1];
          if (i > 0 and j + 1 < n)
            sum += a[i - 1][j + 1];
          if (i + 1 < n and j > 0)
            sum += a[i + 1][j - 1];
          if (i + 1 < n and j + 1 < n)
            sum += a[i + 1][j + 1];
          return sum;
        }
      }
    }
    return -1;
  }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

struct DSU {
  int n;
  vector<int> p;
  vector<int> size;

  void init(int _n) {
    n = _n;
    p.resize(n);
    size.resize(n);
    size.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    int r = x;
    while (p[r] != r)
      r = p[r];
    for (int i = x; p[i] != r;) {
      int j = p[i];
      p[i] = r;
      i = j;
    }
    return r;
  }

  void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      p[y] = x;
      size[x] += size[y];
    }
  }
} dsu;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    int n = cells.size(), ans = -1;
    int top = n + 1, bottom = n + 2;

    dsu.init(n + 3);
    vector<vector<int>> g(row, vector<int>(col, 1));

    for (int i = n - 1; i >= 0; i--) {
      int x = cells[i][0] - 1, y = cells[i][1] - 1;
      g[x][y] = 0;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < row && ny >= 0 && ny < col && g[nx][ny] == 0)
          dsu.join(x * col + y, nx * col + ny);
      }
      if (x == 0)
        dsu.join(top, y);
      if (x == row - 1)
        dsu.join(bottom, x * col + y);

      if (dsu.find(top) == dsu.find(bottom))
        return i;
    }
    return 0;
  }
};

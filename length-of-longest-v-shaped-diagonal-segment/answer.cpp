template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

const int N = 501;

const int dx[] = {-1, +1, +1, -1};
const int dy[] = {+1, +1, -1, -1};

class Solution {
  int dp[N][N][4][2];

  void init(int n, int m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++)
          dp[i][j][k][0] = dp[i][j][k][1] = INT_MIN;
      }
    }
  }

public:
  int lenOfVDiagonal(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    init(n, m);

    function<int(int, int, int, int)> dfs = [&](int x, int y, int dir,
                                                int turned) -> int {
      int &res = dp[x][y][dir][turned];
      if (res != INT_MIN)
        return res;

      res = 1;
      if (a[x][y] == 1) {
        int x2 = x + dx[dir], y2 = y + dy[dir];
        if (inside(n, m, x2, y2) and a[x2][y2] == 2) {
          int got = dfs(x2, y2, dir, turned);
          umax(res, got + 1);
        }
      } else {
        int other = 2 - a[x][y];

        int x2 = x + dx[dir], y2 = y + dy[dir]; // same dir
        if (inside(n, m, x2, y2) and a[x2][y2] == other) {
          int got = dfs(x2, y2, dir, turned);
          umax(res, got + 1);
        }

        int x3 = x + dx[(dir + 1) % 4],
            y3 = y + dy[(dir + 1) % 4]; // turned dir
        if (turned == 0 and inside(n, m, x3, y3) and a[x3][y3] == other) {
          int got = dfs(x3, y3, (dir + 1) % 4, 1);
          umax(res, got + 1);
        }
      }
      return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != 1)
          continue;
        for (int k = 0; k < 4; k++) {
          int got = dfs(i, j, k, 0);
          umax(ans, got);
        }
      }
    }
    return ans;
  }
};

// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

const int N = 27;

int earliest[N][N][N];
int latest[N][N][N];

class Solution {
private:
  void dfs(int a, int b, int c) {
    // a, (x), b, (y), c
    if (earliest[a][b][c] != -1)
      return;
    if (a == c) {
      earliest[a][b][c] = latest[a][b][c] = 1;
      return;
    }

    earliest[a][b][c] = INT_MAX;
    latest[a][b][c] = INT_MIN;

    if (a > c) {
      int bmin = 0, bmax = b;
      if (a - c - 1 < b) {
        int extra = b - (a - c);
        bmin = (extra + 1) / 2;
        bmax = bmin + (a - c - 1);
      }

      for (int k = 0; k <= c; k++) {
        for (int j = bmin; j <= bmax; j++) {
          int rem = (a + b + c + 2 + 1) / 2;
          int i = rem - 2 - j - k;
          if (i < 0)
            continue;
          dfs(i, j, k);
          umin(earliest[a][b][c], earliest[i][j][k] + 1);
          umax(latest[a][b][c], latest[i][j][k] + 1);
        }
      }
    } else {
      int bmin = 0, bmax = b;
      if (c - a - 1 < b) {
        int extra = b - (c - a);
        bmin = (extra + 1) / 2;
        bmax = bmin + (c - a - 1);
      }

      for (int i = 0; i <= a; i++) {
        for (int j = bmin; j <= bmax; j++) {
          int rem = (a + b + c + 2 + 1) / 2;
          int k = rem - 2 - j - i;
          if (k < 0)
            continue;
          dfs(i, j, k);
          umin(earliest[a][b][c], earliest[i][j][k] + 1);
          umax(latest[a][b][c], latest[i][j][k] + 1);
        }
      }
    }
  }

public:
  vector<int> earliestAndLatest(int n, int x, int y) {
    memset(earliest, -1, sizeof(earliest));
    memset(latest, -1, sizeof(latest));
    int a = x - 1, b = y - x - 1, c = n - y;
    dfs(a, b, c);
    return {earliest[a][b][c], latest[a][b][c]};
  }
};

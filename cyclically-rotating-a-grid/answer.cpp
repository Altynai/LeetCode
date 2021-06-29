class Solution {
public:
  vector<vector<int>> rotateGrid(vector<vector<int>> &a, int k) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> b = a;

    auto rotate = [&](int &x, int &y, int steps, int minr, int maxr, int minc,
                      int maxc) {
      while (steps--) {
        // up
        if (x == minr) {
          if (y == minc) {
            x++;
          } else {
            y--;
          }
        }
        // down
        else if (x == maxr) {
          if (y == maxc) {
            x--;
          } else {
            y++;
          }
        }
        // left
        else if (y == minc) {
          x++;
        }
        // right
        else {
          x--;
        }
      }
    };

    for (int minr = 0, maxr = n - 1, minc = 0, maxc = m - 1;
         minr <= maxr && minc <= maxc; minr++, maxr--, minc++, maxc--) {
      int len = (maxr - minr + 1) * 2 + (maxc - minc + 1) * 2 - 4;
      int steps = k % len;
      // up & down
      for (int j = minc; j <= maxc; j++) {
        int x = minr, y = j;
        int val = a[x][y];
        rotate(x, y, steps, minr, maxr, minc, maxc);
        b[x][y] = val;

        x = maxr, y = j;
        val = a[x][y];
        rotate(x, y, steps, minr, maxr, minc, maxc);
        b[x][y] = val;
      }
      // left & right
      for (int i = minr + 1; i < maxr; i++) {
        int x = i, y = minc;
        int val = a[x][y];
        rotate(x, y, steps, minr, maxr, minc, maxc);
        b[x][y] = val;

        x = i, y = maxc;
        val = a[x][y];
        rotate(x, y, steps, minr, maxr, minc, maxc);
        b[x][y] = val;
      }
    }
    return b;
  }
};

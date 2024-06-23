template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int minimumArea(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int r0 = n, r1 = -1;
    int c0 = m, c1 = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0)
          continue;
        umin(r0, i), umax(r1, i);
        umin(c0, j), umax(c1, j);
      }
    }
    return (r1 - r0 + 1) * (c1 - c0 + 1);
  }
};

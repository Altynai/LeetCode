class Solution {
public:
  vector<vector<int>> specialGrid(int n) {
    vector<vector<int>> p(1 << n, vector<int>(1 << n, -1));

    function<void(int, int, int, int, int, int)> dfs =
        [&](int x0, int x1, int y0, int y1, int l, int r) {
          if (x0 == x1) {
            assert(y0 == y1);
            p[x0][y0] = l;
            return;
          }

          int group = (r - l + 1) / 4;
          int xmid = (x0 + x1) / 2;
          int ymid = (y0 + y1) / 2;

          // top-right
          dfs(x0, xmid, ymid + 1, y1, l, l + group - 1);
          // bottom-right
          dfs(xmid + 1, x1, ymid + 1, y1, l + group, l + group * 2 - 1);
          // bottom-left
          dfs(xmid + 1, x1, y0, ymid, l + group * 2, l + group * 3 - 1);
          // top-left
          dfs(x0, xmid, y0, ymid, l + group * 3, l + group * 4 - 1);
        };
    dfs(0, (1 << n) - 1, 0, (1 << n) - 1, 0, (1 << (n + n)) - 1);
    return p;
  }
};

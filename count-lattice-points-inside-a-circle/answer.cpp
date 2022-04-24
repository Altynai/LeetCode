const int N = 201;

class Solution {
public:
  int countLatticePoints(vector<vector<int>> &c) {
    int n = c.size();
    vector<vector<bool>> vis(N, vector<bool>(N, 0));

    auto is_inside = [&](int k, int x, int y) -> bool {
      int dx = c[k][0] - x;
      int dy = c[k][1] - y;
      return dx * dx + dy * dy <= c[k][2] * c[k][2];
    };

    int ans = 0;
    for (int k = 0; k < n; k++) {
      for (int x = c[k][0] - c[k][2]; x <= c[k][0] + c[k][2]; x++) {
        for (int y = c[k][1] - c[k][2]; y <= c[k][1] + c[k][2]; y++) {
          if (!vis[x][y] and is_inside(k, x, y)) {
            vis[x][y] = 1;
            ans++;
          }
        }
      }
    }
    return ans;
  }
};

const int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

class Solution {
public:
  bool checkMove(vector<vector<char>> &a, int r, int c, char color) {
    char other = (color == 'B' ? 'W' : 'B');
    auto inside = [&](int x, int y) -> bool {
      return x >= 0 && x < 8 && y >= 0 && y < 8;
    };

    for (int k = 0; k < 8; k++) {
      int cnt = 1;
      int x = r + dx[k], y = c + dy[k];
      while (inside(x, y) && a[x][y] == other) {
        cnt++;
        x += dx[k];
        y += dy[k];
      }
      if (inside(x, y) && a[x][y] == color && cnt >= 2)
        return 1;
    }
    return 0;
  }
};

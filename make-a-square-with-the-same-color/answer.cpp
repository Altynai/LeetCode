class Solution {
public:
  bool canMakeSquare(vector<vector<char>> &grid) {
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        int w = 0, b = 0;
        for (int x = 0; x <= 1; x++) {
          for (int y = 0; y <= 1; y++) {
            if (grid[i + x][j + y] == 'W')
              w++;
            else
              b++;
          }
        }
        if (max(w, b) >= 3)
          return 1;
      }
    }
    return 0;
  }
};

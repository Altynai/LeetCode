class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
    int m = rectangles.size();

    // horizontal cut:
    // scan by y, then connect two with DSU if y intersects
    sort(rectangles.begin(), rectangles.end(),
         [](auto &lhs, auto &rhs) { return lhs[1] < rhs[1]; });
    int cnt = 0;
    for (int i = 0; i < m;) {
      int y_low = rectangles[i][1];
      int y_high = rectangles[i][3];
      int j = i;
      while (j < m) {
        int y0 = rectangles[j][1];
        int y1 = rectangles[j][3];
        if (max(y_low, y0) < min(y_high, y1)) {
          y_high = max(y_high, y1);
          j++;
        } else {
          break;
        }
      }
      cnt++;
      i = j;
    }
    if (cnt >= 3)
      return 1;

    // vertical cut
    sort(rectangles.begin(), rectangles.end(),
         [](auto &lhs, auto &rhs) { return lhs[0] < rhs[0]; });
    cnt = 0;
    for (int i = 0; i < m;) {
      int x_low = rectangles[i][0];
      int x_high = rectangles[i][2];
      int j = i;
      while (j < m) {
        int x0 = rectangles[j][0];
        int x1 = rectangles[j][2];
        if (max(x_low, x0) < min(x_high, x1)) {
          x_high = max(x_high, x1);
          j++;
        } else {
          break;
        }
      }
      cnt++;
      i = j;
    }

    return cnt >= 3;
  }
};

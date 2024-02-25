class Solution {
public:
  long long largestSquareArea(vector<vector<int>> &bottomLeft,
                              vector<vector<int>> &topRight) {
    int n = bottomLeft.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x0 = max(bottomLeft[i][0], bottomLeft[j][0]);
        int y0 = max(bottomLeft[i][1], bottomLeft[j][1]);
        int x1 = min(topRight[i][0], topRight[j][0]);
        int y1 = min(topRight[i][1], topRight[j][1]);
        if (x0 <= x1 and y0 <= y1)
          ans = max(ans, min(x1 - x0, y1 - y0));
      }
    }
    return 1LL * ans * ans;
  }
};

class Solution {
public:
  int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
    int n = points.size(), ans = 0;
    sort(points.begin(), points.end());
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and points[j][0] - points[i][0] <= w)
        j++;
      ans++;
      i = j;
    }
    return ans;
  }
};

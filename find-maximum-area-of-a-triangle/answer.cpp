using int64 = long long;

class Solution {
public:
  int64 getMaxArea(vector<vector<int>> &p) {
    int n = p.size();
    map<int, vector<int>> axis;
    for (auto point : p)
      axis[point[0]].push_back(point[1]);

    int64 res = -1;
    int64 minx = axis.begin()->first;
    int64 maxx = prev(axis.end())->first;
    for (auto &[x, ys] : axis) {
      sort(ys.begin(), ys.end());
      int m = ys.size();
      if (m >= 2) {
        int64 a = ys[m - 1] - ys[0];
        int64 b = maxx - x;
        if (x != minx)
          b = max(b, x - minx);
        if (b > 0)
          res = max(res, a * b);
      }
    }
    return res;
  }

  long long maxArea(vector<vector<int>> &p) {
    int64 ans = -1;
    ans = max(ans, getMaxArea(p));
    for (auto &point : p)
      swap(point[0], point[1]);
    ans = max(ans, getMaxArea(p));
    return ans;
  }
};

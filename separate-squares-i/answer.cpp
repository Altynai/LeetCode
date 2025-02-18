const double EPS = 1e-6;

class Solution {
public:
  double separateSquares(vector<vector<int>> &sq) {
    int n = sq.size();
    double area = 0;
    for (int i = 0; i < n; i++)
      area += (double)sq[i][2] * sq[i][2];

    auto Test = [&](double y) -> bool {
      double below = 0;
      for (int i = 0; i < n; i++) {
        if (y <= sq[i][1])
          continue;
        double up = min(y, (double)sq[i][1] + sq[i][2]);
        below += (up - sq[i][1]) * sq[i][2];
      }
      double above = area - below;
      return below >= above;
    };

    double l = 2e9, r = 0;
    for (int i = 0; i < n; i++) {
      l = min(l, (double)sq[i][1]);
      r = max(r, (double)sq[i][1] + sq[i][2]);
    }

    double ans = -1;
    while (r - l > EPS) {
      double mid = (r - l) / 2 + l;
      if (Test(mid))
        ans = mid, r = mid;
      else
        l = mid;
    }
    return ans;
  }
};

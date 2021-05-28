class Solution {
public:
  int minSpeedOnTime(vector<int> &d, double hour) {
    int n = d.size(), ans = -1;
    for (int l = 1, r = 1e7; l <= r;) {
      int m = (l + r) >> 1;
      double time = 0;
      for (int i = 0; i < n - 1; i++) {
        time += (d[i] + m - 1) / m;
      }
      time += ((double)d[n - 1]) / m;
      if (time <= hour) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};

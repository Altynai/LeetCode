using int64 = long long;

class Solution {
private:
  int64 calHeight(int64 sum) {
    int64 res = -1;
    for (int64 l = 0, r = 1e9; l <= r;) {
      int64 mid = (l + r) / 2;
      if (mid * (mid + 1) / 2 <= sum)
        l = mid + 1, res = mid;
      else
        r = mid - 1;
    }
    return res;
  }

public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    int64 ans = -1;
    for (int64 l = 0, r = 1e18; l <= r;) {
      int64 tm = (l + r) / 2, h = 0;
      // 1 + 2 + ... + x <= tm / workerTime
      for (int wt : workerTimes)
        h += calHeight(tm / wt);
      if (h >= mountainHeight)
        r = tm - 1, ans = tm;
      else
        l = tm + 1;
    }
    return ans;
  }
};

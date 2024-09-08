using int64 = long long;

class Solution {
public:
  int maxPossibleScore(vector<int> &a, int d) {
    sort(a.begin(), a.end());
    int ans = -1, n = a.size();
    for (int l = 0, r = 2e9; l <= r;) {
      int64 mid = (1LL * l + r) / 2;
      int64 x = a[0];
      bool good = 1;
      for (int i = 1; good and i < n; i++) {
        x = max(x + mid, 1LL * a[i]);
        if (x > a[i] + d)
          good = 0;
      }
      if (good)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};

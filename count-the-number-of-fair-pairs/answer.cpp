using int64 = long long;

class Solution {
public:
  long long countFairPairs(vector<int> &a, int lower, int upper) {
    int n = a.size();
    sort(a.begin(), a.end());

    int64 ans = 0;
    for (int i = 1; i < n; i++) {
      int x = lower - a[i], y = upper - a[i];
      // minimal l: a[l] <= x
      int l = lower_bound(a.begin(), a.begin() + i, x) - a.begin();
      if (l == i)
        continue;

      // maximal r: y <= a[r]
      int r = lower_bound(a.begin(), a.begin() + i, y + 1) - a.begin();
      if (l < r)
        ans += r - l;
    }
    return ans;
  }
};

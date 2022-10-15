using int64 = long long;

class Solution {
public:
  int minimizeArrayValue(vector<int> &a) {
    int n = a.size(), ans = -1;
    for (int l = 0, r = 1e9 + 7; l <= r;) {
      int mid = (l + r) / 2;

      vector<int64> b(n);
      for (int i = 0; i < n; i++)
        b[i] = a[i];

      for (int i = n - 1; i >= 1; i--) {
        if (b[i] > mid) {
          int64 x = b[i] - mid;
          b[i] -= x;
          b[i - 1] += x;
        }
      }

      if (b[0] <= mid)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

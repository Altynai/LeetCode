using int64 = long long;

class Solution {
public:
  int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int64 ans = -1, d3 = lcm(1LL * divisor1, 1LL * divisor2);
    for (int64 l = 1, r = INT_MAX; l <= r;) {
      int64 mid = l + (r - l) / 2;

      // fit in arr1
      int64 x = mid - mid / divisor1;
      // fit in arr2
      int64 y = mid - mid / divisor2;
      // fit in both
      // divisible by divisor1 && divisible by divisor2
      int64 z = mid - (mid / divisor1 + mid / divisor2 - mid / d3);

      // only fit in arr1 and arr2
      x -= z, y -= z;

      int64 need1 = max(0LL, 1LL * uniqueCnt1 - x);
      int64 need2 = max(0LL, 1LL * uniqueCnt2 - y);

      if (z >= need1 + need2)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

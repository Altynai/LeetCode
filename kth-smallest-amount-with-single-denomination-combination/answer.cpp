using int64 = long long;

#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  long long findKthSmallest(vector<int> &coins, int k) {
    int n = coins.size();

    // count # of combinations when amount value <= x
    auto Count = [&](int64 x) -> int64 {
      int64 res = 0;
      for (int mask = 1; mask < (1 << n); mask++) {
        int64 y = 1; // LCM
        int m = 0;
        for (int i = 0; i < n; i++) {
          if (bit(mask, i)) {
            m++;
            y = lcm(y, 1LL * coins[i]);
          }
        }
        if (m & 1)
          res += x / y;
        else
          res -= x / y;
      }
      return res;
    };

    int64 ans = -1;
    for (int64 l = 1, r = 1e18; l <= r;) {
      int64 mid = (l + r) / 2;
      if (Count(mid) >= k)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

#define bit(n, i) (((n) >> (i)) & 1)

using int64 = long long;

class Solution {
public:
  bool checkEqualPartitions(vector<int> &a, long long target) {
    int n = a.size();
    for (int mask = 1; mask < (1 << n) - 1; mask++) {
      int64 x = 1, y = 1;
      bool good = 1;
      for (int i = 0; good and i < n; i++) {
        if (bit(mask, i)) {
          x *= a[i];
          if (x > target)
            good = 0;
        } else {
          y *= a[i];
          if (y > target)
            good = 0;
        }
      }
      if (good and x == target and y == target)
        return 1;
    }
    return 0;
  }
};

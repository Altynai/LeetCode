#define bit(n, i) (((n) >> (i)) & 1)

using int64 = long long;

class Solution {
public:
  long long maxStrength(vector<int> &a) {
    int n = a.size();
    int64 ans = a[0];
    for (int mask = 1; mask < (1 << n); mask++) {
      int64 m = 1;
      for (int i = 0; i < n; i++) {
        if (bit(mask, i))
          m *= a[i];
      }
      ans = max(ans, m);
    }
    return ans;
  }
};

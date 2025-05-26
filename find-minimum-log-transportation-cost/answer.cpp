using int64 = long long;

class Solution {
public:
  long long minCuttingCost(int n, int m, int k) {
    int64 ans = 0;
    if (n > k)
      ans += 1LL * (n - k) * k;
    if (m > k)
      ans += 1LL * (m - k) * k;
    return ans;
  }
};

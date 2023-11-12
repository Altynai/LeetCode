using int64 = long long;

class Solution {
public:
  long long distributeCandies(int n, int limit) {
    if (limit * 3 < n)
      return 0;
    int64 ans = 0;
    for (int i = 0; i <= min(n, limit); i++) {
      int ma = min(limit, n - i);
      int mi = max(0, n - i - limit);
      if (ma >= mi)
        ans += ma - mi + 1;
    }
    return ans;
  }
};

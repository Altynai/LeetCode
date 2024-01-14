using int64 = long long;

#define bit(n, i) (((n) >> (i)) & 1)

const int N = 49;

class Solution {
private:
  int64 cal(int64 n, int x) {
    int64 ans = 0;
    n += 1; // because we are counting 0 as well
    for (int i = N; i >= 1; i--) {
      if (i % x != 0)
        continue;

      int64 group_size = 1LL << i; // 2^(i - 1) of 0, followed by 2^(i - 1) of 1
      int64 group = n / group_size;
      ans += group * (1LL << (i - 1));
      // last group
      ans += max(0LL, (n % group_size) - (1LL << (i - 1)));
    }
    return ans;
  }

public:
  long long findMaximumNumber(long long k, int x) {
    int64 ans = -1;
    for (int64 l = 1, r = 1e15; l <= r;) {
      int64 mid = (l + r) / 2;
      if (cal(mid, x) <= k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};

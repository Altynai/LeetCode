#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  vector<int> maximumBobPoints(int n, vector<int> &a) {
    const int N = 12;
    vector<int> ans(N, 0);

    auto score = [&](int mask, bool fill) -> int {
      int m = 0, s = 0;
      for (int i = N - 1; i >= 1; i--) {
        if (bit(mask, i)) {
          m += a[i] + 1;
          s += i;
          if (fill)
            ans[i] = a[i] + 1;
        }
      }
      if (fill and m <= n)
        ans[0] = n - m;
      return m <= n ? s : -1;
    };

    int p = -1, s = -1;
    for (int mask = 1; mask < (1 << N); mask++) {
      int got = score(mask, false);
      if (got > s)
        s = got, p = mask;
    }

    score(p, true);
    return ans;
  }
};

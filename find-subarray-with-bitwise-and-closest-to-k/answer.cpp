#define bit(n, i) (((n) >> (i)) & 1)

const int N = 31;

class Solution {
public:
  int minimumDifference(vector<int> &a, int k) {
    int n = a.size();

    vector<int> cnt(N, 0);
    auto Update = [&](int x, int d, int len) -> int {
      int val = 0;
      for (int i = 0; i < N; i++) {
        if (bit(x, i))
          cnt[i] += d;
        if (cnt[i] == len)
          val |= (1 << i);
      }
      return val;
    };

    int ans = INT_MAX;

    // k >= AND value
    for (int l = 0, r = 0; r < n; r++) {
      ans = min(ans, abs(k - a[r]));

      int val = Update(a[r], +1, r - l + 1);
      while (k >= val and l < r) {
        ans = min(ans, k - val);
        val = Update(a[l], -1, r - l);
        l++;
      }
    }

    // k < AND value
    cnt.assign(N, 0);
    for (int l = 0, r = 0; r < n; r++) {
      int val = Update(a[r], +1, r - l + 1);
      while (k >= val and l < r) {
        val = Update(a[l], -1, r - l);
        l++;
      }
      if (k < val)
        ans = min(ans, val - k);
    }
    return ans;
  }
};

const int N = 31;

#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int minimumSubarrayLength(vector<int> &a, int k) {
    int n = a.size(), ans = -1;
    vector<int> cnt(N, 0);
    int val = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j <= i or (j < n and val < k)) {
        for (int pos = 0; pos < N; pos++) {
          if (bit(a[j], pos)) {
            if (cnt[pos]++ == 0)
              val |= (1 << pos);
          }
        }
        j++;
      }
      if (val >= k)
        ans = (ans == -1 ? j - i : min(ans, j - i));
      for (int pos = 0; pos < N; pos++) {
        if (bit(a[i], pos)) {
          if (--cnt[pos] == 0)
            val ^= (1 << pos);
        }
      }
    }
    return ans;
  }
};

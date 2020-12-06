#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minimumIncompatibility(vector<int> &a, int k) {
    int n = a.size();
    int m = n / k; // batch size
    map<int, int> cnt;
    for (int num : a) {
      if (++cnt[num] > k)
        return -1;
    }

    int M = 1 << n;
    vector<int> dp(M, INT_MAX);
    dp[0] = 0;

    // pre-calculation
    vector<int> bits(M, 0);
    vector<int> diff(M, INT_MAX);
    for (int mask = 1; mask < M; mask++) {
      bits[mask] = bitCount(mask);

      if (bits[mask] == m) {
        int mi = INT_MAX, ma = INT_MIN;
        set<int> seen;
        bool duplicated = 0;
        for (int j = 0; j < n; j++) {
          if (bit(mask, j)) {
            if (seen.count(a[j]))
              duplicated = 1;
            seen.insert(a[j]);
            umax(ma, a[j]);
            umin(mi, a[j]);
          }
        }
        if (!duplicated)
          diff[mask] = ma - mi;
      }
    }

    for (int mask = 0; mask < M; mask++) {
      if (bits[mask] < m)
        continue;

      for (int x = mask; x > 0; x = mask & (x - 1)) {
        if (bits[x] == m && diff[x] != INT_MAX && dp[mask ^ x] != INT_MAX) {
          umin(dp[mask], dp[mask ^ x] + diff[x]);
        }
      }
    }
    return dp[M - 1] == INT_MAX ? -1 : dp[M - 1];
  }
};

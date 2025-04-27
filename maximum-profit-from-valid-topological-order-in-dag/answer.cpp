#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxProfit(int n, vector<vector<int>> &edges, vector<int> &score) {
    vector<int> must(n, 0);
    for (auto e : edges)
      must[e[1]] |= (1 << e[0]);

    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      if (dp[mask] == -1)
        continue;
      int bc = bitCount(mask);
      for (int i = 0; i < n; i++) {
        if (bit(mask, i))
          continue;
        if (must[i] > 0 and (mask & must[i]) != must[i])
          continue;
        umax(dp[mask | (1 << i)], dp[mask] + (bc + 1) * score[i]);
      }
    }
    return dp[(1 << n) - 1];
  }
};

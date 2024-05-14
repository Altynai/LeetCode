#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  vector<int> findPermutation(vector<int> &a) {
    int n = a.size();

    // it's fine to always set first position to 0 as the array is cyclic
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

    // we start to scan from the end of the array, which makes tracking the
    // "lexicographically smallest" much easier

    // {previous digit, previous mask}
    using State = pair<int, int>;
    vector<vector<State>> prev(1 << n, vector<State>(n, {-1, -1}));
    for (int i = 1; i < n; i++)
      dp[(1 << i) | (1 << 0)][i] = abs(i - a[0]);

    for (int mask = 1; mask < (1 << n); mask++) {
      for (int last = 0; last < n; last++) {
        if (dp[mask][last] == INT_MAX)
          continue;

        int val = dp[mask][last];
        for (int now = 1; now < n; now++) {
          if (bit(mask, now))
            continue;

          int mask2 = mask | (1 << now);
          int val2 = val + abs(now - a[last]);
          pair<int, int> p = {last, mask};
          if (val2 < dp[mask2][now] or
              (val2 == dp[mask2][now] and p < prev[mask2][now])) {
            dp[mask2][now] = val2;
            prev[mask2][now] = p;
          }
        }
      }
    }

    int best = INT_MAX, last = -1;
    for (int j = 0, mask = (1 << n) - 1; j < n; j++) {
      if (dp[mask][j] == INT_MAX)
        continue;
      int val = dp[mask][j] + abs(0 - a[j]);
      if (val < best or (val == best and j < last)) {
        best = val;
        last = j;
      }
    }

    vector<int> ans = {0};
    for (int mask = (1 << n) - 1; last != -1;) {
      auto [last2, mask2] = prev[mask][last];
      ans.push_back(last);
      mask = mask2, last = last2;
    }
    return ans;
  }
};

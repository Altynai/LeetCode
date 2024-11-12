class Solution {
public:
  bool hasIncreasingSubarrays(vector<int> &a, int k) {
    // dp[i]: maximal good subarray length
    // i, i + 1, i + 2, .... , i + dp[i] - 1
    //                   j, j + 1, ............, j + dp[j] - 1

    // assume i < j <= i + dp[i]
    // we just need to find a maximal j where j - i <= dp[j]
    // i >= j - dp[j]

    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] < a[i + 1])
        dp[i] = dp[i + 1] + 1;
    }

    int ans = 0;
    set<pair<int, int>> vals = {{(n - 1) - dp[n - 1], n - 1}};
    set<int> indices = {n - 1};

    for (int i = n - 2, j = n - 1; i >= 0; i--) {
      while (j > i + dp[i]) {
        vals.erase({j - dp[j], j});
        indices.erase(j);
        j--;
      }
      while (vals.size() and i < prev(vals.end())->first) {
        auto it = prev(vals.end());
        int idx = it->second;
        vals.erase(it);
        indices.erase(idx);
      }
      if (indices.size())
        ans = max(ans, *prev(indices.end()) - i);

      vals.insert({i - dp[i], i});
      indices.insert(i);
    }
    return ans >= k;
  }
};

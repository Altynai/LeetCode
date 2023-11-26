using int64 = long long;

class Solution {
public:
  int findMaximumLength(vector<int> &a) {
    int n = a.size();
    vector<int64> psum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      psum[i] = psum[i - 1] + a[i - 1];

    // dp[i]: result for first i numbers
    // last[i]: best sum ended at i, the less, the better (greedy)

    // we know that dp[i] <= dp[i + 1]
    // dp[i] = max(dp[j]) + 1, for j < i, and psum[i] - psum[j] >= last[j]
    // so we can find the biggest j that psum[i] >= psum[j] + last[j]
    // the right part can be maintained in a monotonic stack

    vector<int64> dp(n + 1, 0);
    vector<int64> last(n + 1, 0);

    vector<pair<int64, int>> s = {{0, 0}}; // monotonic increasing stack
    for (int i = 1; i <= n; i++) {
      int m = s.size(), j = -1;
      for (int l = 0, r = m - 1; l <= r;) {
        int mid = (l + r) / 2;
        if (psum[i] >= s[mid].first)
          j = s[mid].second, l = mid + 1;
        else
          r = mid - 1;
      }
      assert(j != -1);
      dp[i] = dp[j] + 1;
      last[i] = psum[i] - psum[j];
      // a smaller sum can always replace the top element
      // this can benefit us with a bigger index j
      while (!s.empty() and last[i] + psum[i] <= s.back().first)
        s.pop_back();
      s.push_back({last[i] + psum[i], i});
    }
    return dp[n];
  }
};

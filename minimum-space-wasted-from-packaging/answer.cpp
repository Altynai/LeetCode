class Solution {
public:
  int minWastedSpace(vector<int> &a, vector<vector<int>> &b) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i - 1];

    auto cal = [&](int j) -> long long {
      int m = b[j].size();
      sort(b[j].begin(), b[j].end());
      if (b[j][m - 1] < a[n - 1])
        return -1;

      long long ans = 0;
      int l = 0;
      for (int val : b[j]) {
        if (l >= n)
          break;
        auto it = upper_bound(a.begin() + l, a.end(), val);
        int r = it - a.begin();
        if (r > l) {
          ans += 1LL * val * (r - l) - (sum[r] - sum[l]);
          l = r;
        }
      }
      return ans;
    };

    long long ans = -1;
    int m = b.size();
    for (int j = 0; j < m; j++) {
      long long got = cal(j);
      if (got == -1)
        continue;
      if (ans == -1 || got < ans)
        ans = got;
    }
    if (ans == -1)
      return -1;
    return ans % 1000000007;
  }
};

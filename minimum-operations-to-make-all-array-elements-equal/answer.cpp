using int64 = long long;

class Solution {
public:
  vector<long long> minOperations(vector<int> &a, vector<int> &queries) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<int64> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i - 1];

    int m = queries.size();
    vector<int64> ans(m, 0);
    for (int i = 0; i < m; i++) {
      int x = queries[i];
      int idx = upper_bound(a.begin(), a.end(), x) - a.begin() + 1;

      ans[i] += 1LL * x * (idx - 1) - sum[idx - 1];
      if (idx <= n)
        ans[i] += sum[n] - sum[idx - 1] - 1LL * x * (n - idx + 1);
    }
    return ans;
  }
};

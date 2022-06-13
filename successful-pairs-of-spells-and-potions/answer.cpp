class Solution {
public:
  vector<int> successfulPairs(vector<int> &a, vector<int> &b, long long k) {
    int n = a.size(), m = b.size();
    sort(b.begin(), b.end());

    vector<int> ans(n);
    vector<long long> c(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      long long x = (k + a[i] - 1) / a[i];
      ans[i] = m - (lower_bound(c.begin(), c.end(), x) - c.begin());
    }
    return ans;
  }
};

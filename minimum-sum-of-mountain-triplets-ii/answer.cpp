class Solution {
public:
  int minimumSum(vector<int> &a) {
    int n = a.size(), ans = INT_MAX;
    vector<int> suffix(n, a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
      suffix[i] = min(suffix[i + 1], a[i]);
    int prefix = a[0];
    for (int j = 1; j < n - 1; j++) {
      if (prefix < a[j] and a[j] > suffix[j + 1])
        ans = min(ans, prefix + a[j] + suffix[j + 1]);
      prefix = min(prefix, a[j]);
    }
    if (ans == INT_MAX)
      ans = -1;
    return ans;
  }
};

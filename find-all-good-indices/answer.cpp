class Solution {
public:
  vector<int> goodIndices(vector<int> &a, int k) {
    int n = a.size();
    vector<int> f(n, 1), g(n, 1);
    for (int i = 1; i < n; i++)
      f[i] = (a[i] <= a[i - 1] ? f[i - 1] + 1 : 1);
    for (int i = n - 2; i >= 0; i--)
      g[i] = (a[i] <= a[i + 1] ? g[i + 1] + 1 : 1);

    vector<int> ans;
    for (int i = k; i < n - k; i++) {
      if (f[i - 1] >= k and g[i + 1] >= k)
        ans.push_back(i);
    }
    return ans;
  }
};

class Solution {
public:
  vector<int> maxSubsequence(vector<int> &a, int k) {
    int n = a.size();

    vector<int> p(n, 0);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });

    vector<int> ans(p.begin() + n - k, p.end());
    sort(ans.begin(), ans.end());
    for (int &x : ans)
      x = a[x];
    return ans;
  }
};

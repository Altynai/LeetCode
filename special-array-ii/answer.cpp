class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &a, vector<vector<int>> &queries) {
    int n = a.size();
    set<int> bad;
    for (int i = 1; i < n; i++) {
      if ((a[i] & 1) == (a[i - 1] & 1))
        bad.insert(i);
    }

    int m = queries.size();
    vector<bool> ans(m);
    for (int i = 0; i < m; i++) {
      int l = queries[i][0], r = queries[i][1];
      if (l == r)
        ans[i] = true;
      else {
        auto it = bad.lower_bound(l + 1);
        ans[i] = (it == bad.end() or *it > r);
      }
    }
    return ans;
  }
};

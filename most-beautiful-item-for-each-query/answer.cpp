class Solution {
public:
  vector<int> maximumBeauty(vector<vector<int>> &a, vector<int> &q) {
    int n = a.size(), m = q.size();

    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return q[x] < q[y]; });
    sort(a.begin(), a.end());

    int best = 0;
    vector<int> ans(m, 0);
    for (int j = 0, i = 0; j < m; j++) {
      int curPrice = q[p[j]];
      for (; i < n && a[i][0] <= curPrice; i++)
        best = max(best, a[i][1]);
      ans[p[j]] = best;
    }
    return ans;
  }
};

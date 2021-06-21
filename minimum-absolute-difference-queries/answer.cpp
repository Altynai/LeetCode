class Solution {
public:
  vector<int> minDifference(vector<int> &a, vector<vector<int>> &q) {
    int mn = *min_element(a.begin(), a.end()),
        mx = *max_element(a.begin(), a.end());

    vector<vector<int>> pos(mx + 1, vector<int>());
    int n = a.size();
    for (int i = 0; i < n; i++)
      pos[a[i]].push_back(i);

    int m = q.size();
    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
      int l = q[i][0], r = q[i][1];

      vector<int> seen;
      for (int j = mn; j <= mx; j++) {
        auto it = lower_bound(pos[j].begin(), pos[j].end(), l);
        if (it != pos[j].end() && *it <= r)
          seen.push_back(j);
      }

      int k = seen.size();
      if (k >= 2) {
        ans[i] = seen[1] - seen[0];
        for (int w = 2; w < k; w++)
          ans[i] = min(ans[i], seen[w] - seen[w - 1]);
      }
    }
    return ans;
  }
};

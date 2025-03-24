class Solution {
public:
  vector<int> solveQueries(vector<int> &a, vector<int> &queries) {
    int n = a.size(), m = queries.size();

    unordered_map<int, vector<int>> where;
    for (int i = 0; i < n; i++)
      where[a[i]].push_back(i);

    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
      int j = queries[i];
      const vector<int> &indices = where[a[j]];
      int k = indices.size();
      if (k > 1) {
        int p =
            lower_bound(indices.begin(), indices.end(), j) - indices.begin();
        int l = abs(indices[p] - indices[(p - 1 + k) % k]);
        int r = abs(indices[p] - indices[(p + 1) % k]);
        ans[i] = min(min(l, n - l), min(r, n - r));
      }
    }
    return ans;
  }
}

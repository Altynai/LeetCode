class Solution {
public:
  vector<int> path(int x) {
    vector<int> p;
    while (x > 1)
      p.push_back(x), x /= 2;
    p.push_back(x);
    reverse(p.begin(), p.end());
    return p;
  }

  int dist(int u, int v) {
    vector<int> pu = path(u), pv = path(v);
    int nu = pu.size(), nv = pv.size();
    int i = 0, j = 0;
    // find LCA
    while (i < nu and j < nv and pu[i] == pv[j])
      i++, j++;
    i--, j--;
    return nu - 1 - i + nv - 1 - j;
  }

  vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
    int m = queries.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
      ans[i] = dist(queries[i][0], queries[i][1]) + 1;
    return ans;
  }
};

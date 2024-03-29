using int64 = long long;

class Solution {
public:
  vector<long long> unmarkedSumArray(vector<int> &a,
                                     vector<vector<int>> &queries) {
    int n = a.size(), m = queries.size();
    set<pair<int, int>> s;
    int64 sum = 0;
    for (int i = 0; i < n; i++) {
      s.insert({a[i], i});
      sum += a[i];
    }

    vector<bool> marked(n, 0);
    vector<int64> ans(m, 0);
    for (int i = 0; i < m; i++) {
      int j = queries[i][0], k = queries[i][1];
      auto it = s.find({a[j], j});
      if (it != s.end())
        s.erase(it), sum -= a[j];

      while (k > 0 and s.size() > 0) {
        j = s.begin()->second;
        s.erase(s.begin());
        sum -= a[j];
        k--;
      }
      ans[i] = sum;
    }
    return ans;
  }
};

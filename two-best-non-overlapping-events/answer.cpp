class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &e) {
    int ans = 0, n = e.size();
    vector<int> a;
    for (auto &p : e) {
      ans = max(ans, p[2]);
      a.push_back(p[0]);
      a.push_back(p[1]);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int m = a.size();

    vector<vector<int>> ids(m, vector<int>());
    for (int i = 0; i < n; i++) {
      e[i][0] = lower_bound(a.begin(), a.end(), e[i][0]) - a.begin();
      e[i][1] = lower_bound(a.begin(), a.end(), e[i][1]) - a.begin();
      ids[e[i][1]].push_back(i);
    }

    vector<int> dp(m, 0);
    for (int i = 0; i < m; i++) {
      // no pick
      if (i)
        dp[i] = max(dp[i], dp[i - 1]);
      // pick
      for (int id : ids[i]) {
        int l = e[id][0];
        dp[i] = max(dp[i], e[id][2]);
        ans = max(ans, (l ? dp[l - 1] : 0) + e[id][2]);
      }
    }
    return ans;
  }
};

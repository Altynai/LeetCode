class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &c, int m) {
    auto profit = [&](int pass, int total) -> double {
      double now = 1.0 * pass / total;
      double nxt = 1.0 * (pass + 1) / (total + 1);
      return nxt - now;
    };

    int n = c.size();
    set<pair<double, int>> r;
    for (int i = 0; i < n; i++) {
      int pass = c[i][0], total = c[i][1];
      r.insert({profit(pass, total), i});
    }

    while (m--) {
      auto it = prev(r.end());
      auto [added, i] = *it;
      r.erase(it);
      int pass = ++c[i][0], total = ++c[i][1];
      r.insert({profit(pass, total), i});
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
      int pass = c[i][0], total = c[i][1];
      ans += 1.0 * pass / total;
    }
    return ans / n;
  }
};

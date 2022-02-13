class Solution {
public:
  int minimumOperations(vector<int> &a) {
    int n = a.size();

    auto getCount = [&](int s) -> vector<pair<int, int>> {
      unordered_map<int, int> c;
      for (int i = s; i < n; i += 2)
        c[a[i]]++;

      vector<pair<int, int>> ans;
      for (auto [k, v] : c)
        ans.emplace_back(v, k);
      sort(ans.begin(), ans.end());
      return ans;
    };

    vector<pair<int, int>> x = getCount(0), y = getCount(1);
    int ans = INT_MAX, ny = y.size();
    for (auto [cnt, val] : x) {
      bool found = 0;
      for (int d = ny - 1; !found and d >= 0; d--) {
        if (y[d].second != val) {
          ans = min(ans, n - cnt - y[d].first);
          found = 1;
        }
      }
      if (!found)
        ans = min(ans, (n + 1) / 2 - cnt + n / 2);
    }
    return ans;
  }
};

class Solution {
public:
  long long findScore(vector<int> &a) {
    int n = a.size();

    set<pair<int, int>> s;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
      s.insert({a[i], i});

    long long ans = 0;
    while (!s.empty()) {
      auto [val, i] = *s.begin();
      s.erase(s.begin());

      vis[i] = 1;
      ans += val;

      if (i and !vis[i - 1])
        vis[i - 1] = 1, s.erase({a[i - 1], i - 1});
      if (i + 1 < n and !vis[i + 1])
        vis[i + 1] = 1, s.erase({a[i + 1], i + 1});
    }
    return ans;
  }
};

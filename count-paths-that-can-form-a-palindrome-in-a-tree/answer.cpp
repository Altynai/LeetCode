using int64 = long long;

const int N = 26;

class Solution {
public:
  long long countPalindromePaths(vector<int> &p, string s) {
    int n = p.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
      adj[p[i]].push_back(i);

    vector<int> mask(n, 0);
    function<void(int)> dfs = [&](int u) {
      for (int v : adj[u]) {
        int idx = s[v] - 'a';
        mask[v] = (mask[u] ^ (1 << idx));
        dfs(v);
      }
    };
    dfs(0);

    int64 ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      auto it = cnt.find(mask[i]);
      if (it != cnt.end())
        ans += it->second;

      for (int j = 0; j < N; j++) {
        int nmask = (mask[i] ^ (1 << j));
        it = cnt.find(nmask);
        if (it != cnt.end())
          ans += it->second;
      }
      cnt[mask[i]]++;
    }
    return ans;
  }
};

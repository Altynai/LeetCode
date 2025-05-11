using int64 = long long;

class Solution {
public:
  long long maxScore(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    // find cycles and lines
    vector<bool> vis(n, 0);
    vector<int> v;
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      v.push_back(u);
      for (int v : adj[u]) {
        if (!vis[v])
          dfs(v);
      }
    };

    vector<int> cycles, lines;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        v.clear();
        dfs(i);

        int m = v.size();
        if (m == 1)
          continue;

        bool is_cycle = 1;
        for (int x : v) {
          if (adj[x].size() == 1) {
            is_cycle = 0;
            break;
          }
        }
        if (is_cycle)
          cycles.push_back(m);
        else
          lines.push_back(m);
      }
    }

    int64 ans = 0, p = n;
    sort(cycles.rbegin(), cycles.rend());
    for (int x : cycles) {
      // we fill [p - x + 1, ..., p] in the cycle
      int64 l = p - 1, r = p - 2;
      ans += p * l + p * r;

      if (x & 1) {
        for (int i = 0; i < (x - 3) / 2; i++) {
          ans += l * (l - 2) + r * (r - 2);
          l -= 2, r -= 2;
        }
        ans += l * r;
      } else {
        int64 minv = p - x + 1;
        for (int i = 0; i < (x - 2) / 2; i++) {
          ans += l * max(l - 2, minv) + r * max(r - 2, minv);
          l -= 2, r -= 2;
        }
      }

      p -= x;
    }

    sort(lines.rbegin(), lines.rend());
    for (int x : lines) {
      if (x & 1) {
        int64 l = p - 1, r = p - 2;
        ans += p * l + p * r;
        for (int i = 0; i < (x - 3) / 2; i++) {
          ans += l * (l - 2) + r * (r - 2);
          l -= 2, r -= 2;
        }
      } else {
        int64 l = p, r = p - 1;
        ans += l * r;
        for (int i = 0; i < (x - 2) / 2; i++) {
          ans += l * (l - 2) + r * (r - 2);
          l -= 2, r -= 2;
        }
      }

      p -= x;
    }
    return ans;
  }
};

using int64 = long long;

struct Cycle {
  int n;
  vector<int> cycle;
  vector<int64> prefix;

  Cycle() {}
  Cycle(const vector<int> &path) {
    cycle = path;
    n = path.size();
    prefix = vector<int64>(n, path[0]);
    for (int i = 1; i < n; i++)
      prefix[i] = prefix[i - 1] + path[i];
  };

  int64 getValue(int start, int64 k) const {
    // total * repeat
    int64 sum = prefix[n - 1] * (k / n);

    int remain = k % n;
    if (remain > 0) {
      int d = min(remain, n - start);
      sum += rangeSum(start, start + d - 1);
      remain -= d;
      start = (start + d) % n;
    }
    if (remain > 0)
      sum += rangeSum(start, start + remain - 1);
    return sum;
  };

  int64 rangeSum(int l, int r) const {
    return (l == 0 ? prefix[r] : prefix[r] - prefix[l - 1]);
  }
};

class Solution {
public:
  long long getMaxFunctionValue(vector<int> &receiver, long long k) {
    // number of chosen nodes
    k += 1;

    int n = receiver.size();
    int64 ans = 0;

    vector<Cycle> cycles;
    vector<int> cid(n, -1);  // cycle id of node i
    vector<int> cpos(n, -1); // position index of node i insde the cycle

    // find cycles
    vector<int> vis(n, 0);
    vector<int> path, where(n, -1);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      int v = receiver[u];
      if (v == u) {
        cid[u] = cycles.size();
        cpos[0] = 0;
        cycles.push_back(Cycle({u}));
      } else {
        where[u] = path.size();
        path.push_back(u);

        if (vis[v] == 1) {
          vector<int> c(path.begin() + where[v], path.end());
          int m = c.size();
          for (int i = 0; i < m; i++) {
            int x = c[i];
            cid[x] = cycles.size();
            cpos[x] = i;
          }
          cycles.push_back(Cycle(c));
        } else if (vis[v] == 0) {
          dfs(v);
        }
        path.pop_back();
      }
      vis[u] = 2;
    };
    for (int i = 0; i < n; i++) {
      if (vis[i] == 0) {
        path.clear();
        dfs(i);
      }
    }

    // case 1: calculate cycle
    for (const Cycle &cycle : cycles) {
      for (int i = 0; i < cycle.n; i++)
        ans = max(ans, cycle.getValue(i, k));
    }

    // case 2: starts from endpoint
    function<void(int)> dfs2 = [&](int u) {
      path.push_back(u);
      int v = receiver[u];

      // reached a cycle
      if (cid[v] != -1) {
        const Cycle &cycle = cycles[cid[v]];
        int pos = cpos[v];

        // path + cycle
        int m = path.size();
        vector<int64> prefix(m, path[0]);
        for (int i = 1; i < m; i++)
          prefix[i] = prefix[i - 1] + path[i];

        for (int i = 0; i < m; i++) {
          // still on the path
          if (k + i - 1 < m) {
            ans = max(ans, (i == 0 ? prefix[i + k - 1]
                                   : prefix[i + k - 1] - prefix[i - 1]));
          }
          // jumped into cycle
          else {
            // choose [i, m - 1] + cycle
            int64 pathSum =
                (i == 0 ? prefix[m - 1] : prefix[m - 1] - prefix[i - 1]);
            ans = max(ans, pathSum + cycle.getValue(pos, k - (m - i)));
          }
        }
      } else {
        dfs2(v);
      }
    };

    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
      indeg[receiver[i]]++;
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0) {
        path.clear();
        dfs2(i);
      }
    }
    return ans;
  }
};

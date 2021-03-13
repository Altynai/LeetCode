struct fenwick {
#define T int
#define max_m 100005

  T c[max_m];
  int n;

  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void add(int x, T y) {
    if (x == 0) {
      return;
    }
    for (; x <= n; x += x & -x)
      c[x] += y;
  }

  T sum(int x) {
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }
} fw;

class Solution {
public:
  vector<int> countPairs(int n, vector<vector<int>> &edges,
                         vector<int> &queries) {
    vector<int> deg(n, 0);
    vector<vector<int>> e(n, vector<int>());
    int m = edges.size();

    for (auto &edge : edges) {
      int u = edge[0] - 1;
      int v = edge[1] - 1;
      e[u].push_back(v);
      e[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }

    vector<int> ans;
    vector<int> val(n, 0);
    for (int q : queries) {
      int total = 0;
      // calculate invalid: deg[x] + deg[y] - num(x, y) <= q
      // how many y: 0 <= val[y] <= q - deg[x]
      for (int u = 0; u < n; u++)
        val[u] = 0;
      fw.init(m); // SHOULD be the number of edges
      val[n - 1] = deg[n - 1];
      fw.add(val[n - 1], 1);
      // trace(deg, val);
      for (int u = n - 2; u >= 0; u--) {
        // remove edge
        for (int v : e[u]) {
          if (v <= u)
            continue;
          fw.add(val[v], -1);
          val[v] -= 1;
          fw.add(val[v], 1);
        }
        // calculate
        int p = q - deg[u];
        if (p < 0) {
          total += 0;
        } else if (p == 0) {
          // val[y] = 0
          total += n - 1 - u - fw.sum(m);
        } else {
          // 0 <= val[y] <= p
          total += n - 1 - u - (fw.sum(m) - fw.sum(p));
        }
        // add edge back
        for (int v : e[u]) {
          if (v <= u)
            continue;
          fw.add(val[v], -1);
          val[v] += 1;
          fw.add(val[v], 1);
        }
        // add u its self
        val[u] = deg[u];
        fw.add(val[u], 1);
      }
      ans.push_back(n * (n - 1) / 2 - total);
    }
    return ans;
  }
};

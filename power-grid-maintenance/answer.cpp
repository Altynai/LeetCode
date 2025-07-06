struct DSU {
  int n, cnt;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    cnt = n = _n;
    p.resize(n);
    s.resize(n);
    s.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

  bool same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return 0;

    if (x < y)
      swap(x, y);
    p[y] = x;
    s[x] += s[y];
    cnt--;
    return 1;
  }

  int components() { return cnt; }

} dsu;

class Solution {
public:
  vector<int> processQueries(int n, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    dsu.init(n);
    for (auto conn : connections)
      dsu.join(conn[0] - 1, conn[1] - 1);

    vector<bool> online(n, 1);
    vector<int> ids(n, -1);
    unordered_map<int, int> roots;
    int gid = 0;
    for (int i = 0; i < n; i++) {
      int r = dsu.find(i);
      if (roots.count(r) == 0)
        roots[r] = gid++;
      ids[i] = roots[r];
    }

    vector<set<int>> power(gid);
    for (int i = 0; i < n; i++) {
      power[ids[i]].insert(i);
    }

    int q = queries.size();
    vector<int> ans;
    for (int i = 0; i < q; i++) {
      int x = queries[i][1] - 1;
      if (queries[i][0] == 1) {
        if (online[x])
          ans.push_back(x + 1);
        else {
          const set<int> &p = power[ids[x]];
          ans.push_back(p.empty() ? -1 : *p.begin() + 1);
        }
      } else {
        online[x] = 0;
        power[ids[x]].erase(x);
      }
    }
    return ans;
  }
};

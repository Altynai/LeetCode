struct DSU {
  int n;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    n = _n;
    p.resize(n);
    s.resize(n);
    s.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    int r = x;
    while (p[r] != r)
      r = p[r];
    for (int i = x; p[i] != r;) {
      int j = p[i];
      p[i] = r;
      i = j;
    }
    return r;
  }

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
    return 1;
  }
} dsu;

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    int m = meetings.size();
    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(),
         [&](int x, int y) { return meetings[x][2] < meetings[y][2]; });

    dsu.init(n);
    dsu.join(0, firstPerson);

    for (int i = 0; i < m;) {
      int j = i;
      while (j < m && meetings[p[i]][2] == meetings[p[j]][2])
        j++;

      unordered_set<int> people;
      for (int k = i; k < j; k++) {
        int u = meetings[p[k]][0], v = meetings[p[k]][1];
        dsu.join(u, v);
        people.insert(u);
        people.insert(v);
      }

      for (int k : people) {
        if (!dsu.same(k, 0))
          dsu.p[k] = k;
      }

      i = j;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dsu.same(i, 0))
        ans.push_back(i);
    }
    return ans;
  }
};

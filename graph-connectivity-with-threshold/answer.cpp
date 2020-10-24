struct DSU {
#define max_m 10005
  int n;
  int p[max_m];

  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
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

  void join(int x, int y) {
    x = find(x);
    y = find(y);
    p[y] = x;
  }
} dsu;

class Solution {
public:
  vector<bool> areConnected(int n, int threshold,
                            vector<vector<int>> &queries) {
    dsu.init(n + 1);
    for (int i = threshold + 1; i <= n / 2; i++) {
      for (int j = i; j <= n; j += i)
        dsu.join(i, j);
    }

    vector<bool> ans;
    for (auto &q : queries) {
      ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
    }
    return ans;
  }
};

struct DSU {
#define max_m 100005
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
  int minimumHammingDistance(vector<int> &source, vector<int> &target,
                             vector<vector<int>> &allowedSwaps) {
    int n = source.size();
    dsu.init(n);

    for (auto &v : allowedSwaps) {
      int a = v[0], b = v[1];
      if (dsu.find(a) != dsu.find(b))
        dsu.join(a, b);
    }

    unordered_map<int, vector<int>> comp;
    for (int i = 0; i < n; i++) {
      comp[dsu.find(i)].push_back(i);
    }

    int ans = 0;
    for (auto &[r, nodes] : comp) {
      unordered_map<int, int> cnt;
      for (int i : nodes)
        cnt[source[i]] += 1;

      for (int i : nodes) {
        auto it = cnt.find(target[i]);
        if (it != cnt.end() && it->second > 0) {
          it->second -= 1;
        } else {
          ans++;
        }
      }
    }
    return ans;
  }
};

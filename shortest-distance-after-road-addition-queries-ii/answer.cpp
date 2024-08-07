template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    int m = queries.size();

    vector<int> nxt(n);
    iota(nxt.begin(), nxt.end(), 0);

    set<pair<int, int>> segs;
    int jumped = 0;

    auto Add = [&](int l, int r) {
      segs.insert({l, r});
      jumped += r - l;
    };

    auto Remove = [&](int l, int r) {
      auto it = segs.lower_bound({l, l});
      while (it != segs.end() and it->second <= r) {
        jumped -= (it->second - it->first);
        it = segs.erase(it);
      }
    };

    auto IsCovered = [&](int l, int r) -> bool {
      auto it = segs.lower_bound({l, l});
      if (it != segs.begin()) {
        it = prev(it);
        return it->second >= r;
      }
      return false;
    };

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      int u = queries[i][0], v = queries[i][1];
      if (v > nxt[u]) {
        // if u -> v is inside another segment, we can just ignore it
        if (!IsCovered(u, v)) {
          Remove(u, v);
          Add(u, v);
        }
      }
      umax(nxt[u], v);
      ans[i] = n - 1 - jumped + segs.size();
    }
    return ans;
  }
};

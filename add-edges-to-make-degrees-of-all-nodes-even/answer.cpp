class Solution {
public:
  bool isPossible(int n, vector<vector<int>> &edges) {
    vector<int> deg(n, 0);
    set<pair<int, int>> s;

    auto AddEdge = [&](int u, int v) {
      if (u > v)
        swap(u, v);
      s.insert({u, v});
    };

    auto HasEdge = [&](int u, int v) -> bool {
      if (u > v)
        swap(u, v);
      return s.count({u, v}) > 0;
    };

    for (auto &e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      AddEdge(u, v);
      deg[u]++, deg[v]++;
    }

    vector<int> odd;
    for (int i = 0; i < n; i++) {
      if (deg[i] & 1)
        odd.push_back(i);
    }
    int m = odd.size();
    if (m == 0)
      return 1;
    else if (m & 1)
      return 0;
    else if (m >= 6)
      return 0;

    if (m == 2) {
      int u = odd[0], v = odd[1];
      if (!HasEdge(u, v))
        return 1;

      // need to find an intermediate point to connect
      for (int i = 0; i < n; i++) {
        if (i != u and i != v and !HasEdge(u, i) and !HasEdge(v, i))
          return 1;
      }
      return 0;
    }

    // 4 nodes
    vector<int> ord = {0, 1, 2, 3};
    do {
      if (!HasEdge(odd[ord[0]], odd[ord[1]]) and
          !HasEdge(odd[ord[2]], odd[ord[3]]))
        return 1;
    } while (next_permutation(ord.begin(), ord.end()));

    return 0;
  }
};

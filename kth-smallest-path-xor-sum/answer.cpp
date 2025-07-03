#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class Key>
using OrderedSet = tree<Key, null_type, less<Key>, rb_tree_tag,
                        tree_order_statistics_node_update>;

class Solution {
public:
  vector<int> kthSmallest(vector<int> &par, vector<int> &vals,
                          vector<vector<int>> &queries) {
    int n = par.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
      adj[par[i]].push_back(i);

    int m = queries.size();
    // node, [(k, index)]
    unordered_map<int, vector<pair<int, int>>> q;
    for (int i = 0; i < m; i++) {
      int u = queries[i][0], k = queries[i][1];
      q[u].push_back({k - 1, i});
    }

    vector<int> ans(m, -1);
    function<OrderedSet<int> *(int, int)> dfs =
        [&](int u, int xor_val) -> OrderedSet<int> * {
      xor_val ^= vals[u];
      OrderedSet<int> *res = new OrderedSet<int>();
      res->insert(xor_val);

      for (int v : adj[u]) {
        OrderedSet<int> *got = dfs(v, xor_val);
        if (got->size() > res->size()) {
          swap(res, got);
        }
        for (int x : *got)
          res->insert(x);
      }
      auto it = q.find(u);
      if (it != q.end()) {
        int sz = res->size();
        for (auto [k, index] : it->second) {
          if (k >= sz)
            continue;
          ans[index] = *(res->find_by_order(k));
        }
      }
      return res;
    };
    dfs(0, 0);
    return ans;
  }
};

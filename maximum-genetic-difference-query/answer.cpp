struct Node {
  int cnt[2];
  Node *children[2];
  Node() {
    cnt[0] = cnt[1] = 0;
    children[0] = children[1] = nullptr;
  }
};

class Solution {
public:
  vector<int> maxGeneticDifference(vector<int> &parents,
                                   vector<vector<int>> &queries) {
    int n = parents.size(), root = -1;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n; i++) {
      if (parents[i] == -1)
        root = i;
      else
        g[parents[i]].push_back(i);
    }

    int m = queries.size();
    map<int, vector<pair<int, int>>> q;
    for (int i = 0; i < m; i++) {
      q[queries[i][0]].emplace_back(queries[i][1], i);
    }

    const int N = 19;
    auto update = [&](Node *node, int val, int added) {
      for (int i = N; i >= 0; i--) {
        int p = (val >> i) & 1;
        if (node->children[p] == nullptr)
          node->children[p] = new Node();
        node->cnt[p] += added;
        node = node->children[p];
      }
    };

    auto query = [&](Node *node, int val) {
      int ans = 0;
      for (int i = N; i >= 0; i--) {
        int p = (val >> i) & 1;
        p ^= 1;
        if (node->children[p] && node->cnt[p]) {
          ans |= 1 << i;
          node = node->children[p];
        } else {
          node = node->children[p ^ 1];
        }
      }
      return ans;
    };

    vector<int> ans(m, -1);
    Node *r = new Node();
    function<void(int)> dfs = [&](int u) {
      update(r, u, 1);
      for (auto [val, i] : q[u]) {
        ans[i] = query(r, val);
      }
      for (int v : g[u])
        dfs(v);
      update(r, u, -1);
    };
    dfs(root);
    return ans;
  }
};

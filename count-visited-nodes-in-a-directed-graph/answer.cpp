struct StronglyConnectedComponent {
  // Good learning:
  // https://blog.csdn.net/yan_qiu_ynlchrz/article/details/116430077
  // 1. if there is a path u->v of length x, there is a path v->u with length -x
  // 2. if there is a loop of length x passing a, there is a loop with same
  // length passing b
  // 3. loop of arbitrary length can be constucted with some linear combination
  // of loops passing a
  // 4. if G = gcd(all the loop length) passing a, we can construct any loop
  // with length kG

  vector<vector<int>> g;
  vector<bool> inStack;
  vector<int> dfn;
  vector<int> low;
  vector<int> deg;
  stack<int> stk;
  int n, timeStamp;

  void init(int _n) {
    n = _n;
    g = vector<vector<int>>(n, vector<int>());
    inStack.assign(n, false);
    dfn.assign(n, 0);
    low.assign(n, 0);
    deg.assign(n, 0);
    stk = stack<int>();
    timeStamp = 0;
  }

  void add(int u, int v) {
    g[u].push_back(v);
    deg[v]++;
  }

  vector<int> tarjan(int &cnt) {
    cnt = 0;
    vector<int> belong(n, -1);
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0 && !dfn[i])
        tarjan(i, cnt, belong);
    }
    for (int i = 0; i < n; i++) {
      if (!dfn[i])
        tarjan(i, cnt, belong);
    }
    return belong;
  }

  void tarjan(int u, int &cnt, vector<int> &belong) {
    dfn[u] = low[u] = ++timeStamp;
    stk.push(u);
    inStack[u] = 1;
    for (int v : g[u]) {
      if (!dfn[v]) {
        tarjan(v, cnt, belong);
        low[u] = min(low[u], low[v]);
      } else if (inStack[v])
        low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {
      int v;
      do {
        v = stk.top();
        stk.pop();
        belong[v] = cnt;
        inStack[v] = false;
      } while (u != v);
      cnt++;
    }
  }
} scc;

class Solution {
public:
  vector<int> countVisitedNodes(vector<int> &edges) {
    int n = edges.size();

    scc.init(n);
    for (int i = 0; i < n; i++)
      scc.add(i, edges[i]);

    int m = 0;
    vector<int> belong = scc.tarjan(m);

    unordered_map<int, int> freq;
    for (int x : belong)
      freq[x]++;

    // 缩点
    vector<int> adj(m, -1);
    for (int i = 0; i < n; i++) {
      int j = edges[i];
      if (belong[i] != belong[j])
        adj[belong[i]] = belong[j];
    }

    vector<int> sizes(m, -1);
    function<int(int)> dfs = [&](int u) -> int {
      if (sizes[u] != -1)
        return sizes[u];
      if (adj[u] == -1)
        return sizes[u] = freq[u];
      return sizes[u] = freq[u] + dfs(adj[u]);
    };
    for (int i = 0; i < m; i++) {
      if (sizes[i] == -1)
        dfs(i);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = sizes[belong[i]];
    return ans;
  }
};

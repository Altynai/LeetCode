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
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&](int x, int y) { return deg[x] < deg[y]; });

    cnt = 0;
    vector<int> belong(n, -1);
    for (int i = 0; i < n; i++) {
      if (!dfn[a[i]])
        tarjan(a[i], cnt, belong);
    }
    return belong;
  }

  void tarjan(int u, int &cnt, vector<int> &belong) {
    dfn[u] = low[u] = timeStamp++;
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
  int maximumInvitations(vector<int> &fav) {
    int n = fav.size();

    scc.init(n);
    vector<vector<int>> rev(n);
    for (int u = 0; u < n; u++) {
      scc.add(u, fav[u]);
      rev[fav[u]].push_back(u);
    }

    int ans = 0, components = 0;
    vector<int> belongs = scc.tarjan(components);

    // case: one single cycle
    vector<int> cnt(components, 0);
    for (int x : belongs)
      ans = max(ans, ++cnt[x]);

    // case: 2 linked list but with last 2 items formed as a cycle
    // A -> B -> C <-> D <- E <- F <- G
    vector<int> dis(n, -1);
    function<int(int, int)> dfs = [&](int u, int pre) -> int {
      if (dis[u] != -1)
        return dis[u];

      dis[u] = 1;
      for (int x : rev[u]) {
        if (x != pre)
          dis[u] = max(dis[u], dfs(x, u) + 1);
      }
      return dis[u];
    };

    for (int u = 0; u < n; u++) {
      int v = fav[u];
      if (fav[v] == u and dis[u] == -1) {
        dfs(u, v);
      }
    }

    int cc = 0;
    for (int u = 0; u < n; u++) {
      int v = fav[u];
      if (fav[v] == u)
        cc += dis[u] + dis[v];
    }
    ans = max(ans, cc / 2);
    return ans;
  }
};

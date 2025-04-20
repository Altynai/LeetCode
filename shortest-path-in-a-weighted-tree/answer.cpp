using int64 = long long;

struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 200004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int tag[MAXN];
  int64 sum[MAXN];

  inline int rangeSize(int p) { return R[p] - L[p] + 1; }

  void build(int p, int l, int r, const vector<int> &v) {
    L[p] = l, R[p] = r, tag[p] = 0;
    if (l == r) {
      sum[p] = v[l];
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid, v);
      build(rson(p), mid + 1, r, v);
      pull(p);
    }
  }

  void tagNode(int p, int newVal) {
    tag[p] += newVal;
    sum[p] += 1LL * newVal * rangeSize(p);
  }

  void push(int p) {
    // can't push down on leaf nodes
    assert(L[p] != R[p]);
    if (tag[p]) {
      tagNode(lson(p), tag[p]);
      tagNode(rson(p), tag[p]);
    }
    tag[p] = 0;
  }

  void pull(int p) {
    // can't pull on leaf nodes
    assert(L[p] != R[p]);
    sum[p] = sum[lson(p)] + sum[rson(p)];
  }

  void rangeUpdate(int p, int l, int r, int newValue) {
    // case 1: update leaf node
    if (L[p] == R[p]) {
      sum[p] += newValue;
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      tagNode(p, newValue);
    }
    // case 3: may need to split the range
    else {
      // make sure to call push before doing rangeSet on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        rangeUpdate(lson(p), l, r, newValue);
      else if (l > mid)
        rangeUpdate(rson(p), l, r, newValue);
      else {
        rangeUpdate(lson(p), l, mid, newValue);
        rangeUpdate(rson(p), mid + 1, r, newValue);
      }
      // make sure to call pill after doing rangeSet on child nodes
      pull(p);
    }
  }

  int64 query(int p, int l, int r) {
    // case 1: query leaf node
    if (L[p] == R[p]) {
      return sum[p];
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      return sum[p];
    }
    // case 3: may need to split the range
    else {
      // make sure to call push before doing query on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        return query(lson(p), l, r);
      else if (l > mid)
        return query(rson(p), l, r);
      else {
        return query(lson(p), l, mid) + query(rson(p), mid + 1, r);
      }
    }
  }
} st;

class Solution {
public:
  vector<int> treeQueries(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &queries) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto edge : edges) {
      int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<int> fa(n, -1);
    // child, father
    unordered_map<int, unordered_map<int, int>> weights;
    int ts = 0;
    vector<int> l(n), r(n), d;

    function<void(int, int, int)> dfs = [&](int u, int father, int dis) {
      l[u] = ts++;
      d.push_back(dis);
      for (auto [v, w] : adj[u]) {
        if (v == father)
          continue;
        fa[v] = u;
        weights[v][u] = w;
        dfs(v, u, dis + w);
      }
      r[u] = ts++;
      d.push_back(dis);
    };
    dfs(0, -1, 0);

    assert(d.size() == ts);
    st.build(1, 0, ts - 1, d);

    int m = queries.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      int op = queries[i][0];
      if (op == 1) {
        int u = queries[i][1] - 1, v = queries[i][2] - 1, w = queries[i][3];
        if (v == fa[u])
          swap(u, v);
        int diff = w - weights[v][u];
        st.rangeUpdate(1, l[v], r[v], diff);
        weights[v][u] = w;
      } else {
        int x = queries[i][1] - 1;
        int res = st.query(1, l[x], l[x]);
        ans.push_back(res);
      }
    }
    return ans;
  }
};

template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  os << "]";
  return os;
}

template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "]";
}

template <typename T> inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "}";
}

template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "}";
}

template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++)
      os << ", ";
    os << val;
  }
  return os << "]";
}

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) {
  cout << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

// types
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define si set<int>
#define mpii map<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>

// names
#define pb push_back
#define fi first
#define se second
#define mp(a, b) make_pair((a), (b))
#define sz(a) ((int)(a).size())
#define rep(i, s, t) for (int i = (s); i < (t); i++)
#define repn(i, s) for (int i = 0; i < (s); i++)
#define ms(a, b) memset(a, b, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

// constants
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

// =====================================================================================================================
#define maxn 100006

class Solution {
public:
  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
    vi ans(n - 1, 0);
    int d[n][n];

    vvi g(n, vi());
    for (vi &e : edges) {
      int u = e[0], v = e[1];
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }

    function<void(int, int, int, int)> dfs = [&](int root, int u, int fa,
                                                 int dep) {
      d[root][u] = dep;
      for (int v : g[u])
        if (v != fa) {
          dfs(root, v, u, dep + 1);
        }
    };

    // check connected component
    bool vis[n];
    function<void(int, int, int)> dfs2 = [&](int mask, int u, int fa) {
      vis[u] = 1;
      for (int v : g[u])
        if (v != fa && bit(mask, v)) {
          dfs2(mask, v, u);
        }
    };

    repn(i, n) dfs(i, i, -1, 0);

    rep(mask, 1, 1 << n) {
      vi pos;
      repn(i, n) if (bit(mask, i)) pos.pb(i);

      int m = sz(pos);
      if (m <= 1)
        continue;

      ms(vis, 0);
      dfs2(mask, pos[0], -1);
      // some node is not reachable
      bool valid = 1;
      for (int u : pos)
        if (!vis[u])
          valid = 0;
      if (!valid)
        continue;

      int md = 0;
      for (int u : pos)
        for (int v : pos)
          if (u != v)
            umax(md, d[u][v]);
      ans[md - 1]++;
    }
    return ans;
  }
};

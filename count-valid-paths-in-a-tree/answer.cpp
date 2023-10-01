struct DSU {
  int n;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    n = _n;
    p.resize(n);
    s.resize(n);
    s.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

  int size(int x) { return s[find(x)]; }

  bool same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return 0;

    if (x < y)
      swap(x, y);
    p[y] = x;
    s[x] += s[y];
    return 1;
  }
} dsu;

struct PrimeFactorization {

  // primes.size() <= sqrt(n)
  vector<int> primes;
  vector<bool> p;

  PrimeFactorization(int n) {
    p.resize(n);
    p.assign(n, true);

    p[0] = p[1] = 0;
    for (int i = 4; i < n; i += 2)
      p[i] = 0;
    for (int i = 3; i * i < n; i += 2) {
      if (!p[i])
        continue;
      for (int j = i * i; j < n; j += i)
        p[j] = 0;
    }

    primes = {2};
    for (int i = 3; i < n; i += 2)
      if (p[i])
        primes.push_back(i);
  }

  vector<pair<int, int>> getFactors(int n) {
    vector<pair<int, int>> ans;
    for (int i = 0; n > 1 && i < (int)primes.size(); i++) {
      int cnt = 0;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      if (cnt)
        ans.emplace_back(primes[i], cnt);
    }
    if (n > 1)
      ans.emplace_back(n, 1);
    return ans;
  }
} prime_factorization(1e5 + 3);

using int64 = long long;

class Solution {
public:
  long long countPaths(int n, vector<vector<int>> &edges) {
    const vector<int> &primes = prime_factorization.primes;
    const vector<bool> &isPrime = prime_factorization.p;

    dsu.init(n + 1);

    vector<vector<int>> adj(n + 1);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);

      if (!isPrime[e[0]] and !isPrime[e[1]])
        dsu.join(e[0], e[1]);
    }

    int64 ans = 0;
    for (int p : primes) {
      if (p > n)
        break;

      int64 sum = 0, added = 0;
      for (int v : adj[p]) {
        if (!isPrime[v]) {
          sum += dsu.size(v);
        }
      }
      for (int v : adj[p]) {
        if (!isPrime[v]) {
          int sz = dsu.size(v);
          ans += sz;
          added += (sum - sz) * sz;
        }
      }
      ans += added / 2;
    }
    return ans;
  }
};

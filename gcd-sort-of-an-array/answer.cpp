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

struct Prime {
  // primes.size() <= sqrt(n)
  vector<int> primes;

  Prime(int n) {
    vector<bool> p(n, 1);
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

  vector<pair<int, int>> generate(int n) {
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
} prime(100001);

class Solution {
public:
  bool gcdSort(vector<int> &a) {
    const int maxn = 100001;
    dsu.init(maxn);

    int n = a.size();
    vector<int> fact(n, -1);
    for (int i = 0; i < n; i++) {
      if (a[i] == 1)
        continue;
      auto factors = prime.generate(a[i]);
      int m = factors.size();
      fact[i] = factors[0].first;
      for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++)
          dsu.join(factors[j].first, factors[k].first);
      }
    }

    vector<int> b(n, -1);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1)
        b[i] = 1;
      else {
        int root = dsu.find(fact[i]);
        pos[root].emplace_back(i);
      }
    }

    for (auto &[p, indices] : pos) {
      vector<int> vals;
      for (int i : indices)
        vals.emplace_back(a[i]);
      sort(vals.begin(), vals.end());

      int m = indices.size();
      for (int i = 0; i < m; i++)
        b[indices[i]] = vals[i];
    }

    sort(a.begin(), a.end());
    return a == b;
  }
};

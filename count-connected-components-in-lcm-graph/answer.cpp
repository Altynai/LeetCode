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

  int components() {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(find(i));
    return s.size();
  }

} dsu;

class Solution {
public:
  int countComponents(vector<int> &nums, int threshold) {
    int ans = 0;
    vector<int> a;
    for (int x : nums) {
      if (x > threshold)
        ans++;
      else
        a.push_back(x);
    }

    int n = a.size();
    sort(a.begin(), a.end());

    // if there is 1, every number can be connected
    if (n > 0 and a[0] == 1)
      return 1 + ans;

    // a[i] * a[j] / gcd <= threshold
    // a[i] / gcd <= threshold / a[j] = P
    // we can iterate factors of P and it's also a factor of a[j]
    // so a[i] / factor <= P, and we try best to connect every possible factor
    dsu.init(n);
    unordered_map<int, int> where; // index associated with minimum factor

    for (int j = 0; j < n; j++) {
      int p = threshold / a[j];
      for (int factor = 1; factor <= (int)sqrt(a[j]); factor++) {
        if (a[j] % factor == 0) {
          auto it = where.find(factor);
          if (it != where.end()) {
            int i = it->second;
            if (a[i] / factor <= p)
              dsu.join(i, j);
          }

          int other = a[j] / factor;
          it = where.find(other);
          if (it != where.end()) {
            int i = it->second;
            if (a[i] / other <= p)
              dsu.join(i, j);
          }
        }
      }

      // update index
      for (int factor = 1; factor <= (int)sqrt(a[j]); factor++) {
        if (a[j] % factor == 0) {
          if (where.find(factor) == where.end())
            where[factor] = j;
          int other = a[j] / factor;
          if (where.find(other) == where.end())
            where[other] = j;
        }
      }
    }

    return ans + dsu.components();
  }
};

#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

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
} dsu;

class Solution {
public:
  vector<int> groupStrings(vector<string> &words) {
    const int N = 26;

    unordered_map<int, int> where;
    auto convert = [](const string &s) -> int {
      int x = 0;
      for (char c : s)
        x |= (1 << (c - 'a'));
      return x;
    };

    int n = words.size();
    dsu.init(n);
    where[convert(words[0])] = 0;

    for (int i = 1; i < n; i++) {
      int mask = convert(words[i]);
      if (where.count(mask)) {
        dsu.join(where[mask], i);
        continue;
      }

      for (int j = 0; j < N; j++) {
        if (!bit(mask, j)) {
          auto it = where.find(mask | (1 << j));
          if (it != where.end())
            dsu.join(it->second, i);
        } else {
          auto it = where.find(mask ^ (1 << j));
          if (it != where.end()) {
            dsu.join(it->second, i);
            continue;
          }

          for (int k = 0; k < N; k++) {
            it = where.find(mask ^ (1 << j) | (1 << k));
            if (it != where.end())
              dsu.join(it->second, i);
          }
        }
      }
      where[mask] = i;
    }

    unordered_map<int, int> cnt;
    int best = 0;
    for (int i = 0; i < n; i++) {
      int r = dsu.find(i);
      best = max(best, ++cnt[r]);
    }
    return {(int)cnt.size(), best};
  }
};

using int64 = long long;

template <class T> struct Fenwick {
  vector<T> c;
  int n;

  Fenwick(int _n) {
    n = _n;
    c.resize(_n + 1);
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  inline int lowbit(int x) { return x & (-x); }

  void add(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] += val;
  }

  // sum of [1 ... x]
  T sum(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret += c[i];
    return ret;
  }
};

class Solution {
public:
  long long countOperationsToEmptyArray(vector<int> &a) {
    int n = a.size();

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });

    Fenwick<int> bits(n);
    for (int i = 1; i <= n; i++)
      bits.add(i, 1);

    auto Sum = [&](int l, int r) -> int {
      if (l > r)
        return 0;
      return bits.sum(r + 1) - bits.sum(l);
    };

    int64 ans = 0;
    for (int i = 0, cur = 0; i < n; i++) {
      int nxt = p[i];
      if (cur <= nxt)
        ans += Sum(cur, nxt - 1);
      else {
        // the nxt has been moved to the end already, the array looks like [c
        // ... n - 1] [... nxt ...] we first rotate the current left range of [c
        // ... n - 1]
        ans += Sum(cur, n - 1);
        // the array is now set to the orignal order
        ans += Sum(0, nxt - 1);
      }

      cur = nxt;
      bits.add(cur + 1, -1); // remove current smallest from head
      ans++;
    }
    return ans;
  }
};

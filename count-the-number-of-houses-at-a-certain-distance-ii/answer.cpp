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

  void update(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] += val;
  }

  void rangeUpdate(int x, int y, T val) {
    update(x, val);
    update(y + 1, -val);
  }

  // get x
  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret += c[i];
    return ret;
  }
};

using int64 = long long;

class Solution {
public:
  vector<long long> countOfPairs(int n, int x, int y) {
    vector<int64> ans(n, 0);
    if (x == y) {
      for (int i = 1; i <= n; i++)
        ans[i - 1] = (n - i) * 2;
      return ans;
    }

    if (x > y)
      swap(x, y);
    int cycle = y - x + 1;

    // case 0: both in the left
    if (x >= 3) {
      for (int len = x - 2, k = 1; len >= 1; len--, k++)
        ans[k - 1] += len;
    }

    // case 1: both in the right
    if (y + 2 <= n) {
      for (int len = n - y - 1, k = 1; len >= 1; len--, k++)
        ans[k - 1] += len;
    }

    // case 2: both in the cycle
    if (cycle & 1) {
      for (int k = 1; k <= cycle / 2; k++)
        ans[k - 1] += cycle;
    } else {
      for (int k = 1; k < cycle / 2; k++)
        ans[k - 1] += cycle;
      ans[cycle / 2 - 1] += cycle / 2;
    }

    // case 3: a < x and b in the cycle
    Fenwick<int> fw(n);
    if (x >= 2) {
      for (int a = x - 1; a >= 1; a--) {
        int len = x - a;
        if (cycle % 2 == 0) {
          int half = cycle / 2 - 1;
          fw.rangeUpdate(len, len, 1);
          fw.rangeUpdate(len + 1, len + half, 2);
          fw.rangeUpdate(len + half + 1, len + half + 1, 1);
        } else {
          int half = cycle / 2;
          fw.rangeUpdate(len, len, 1);
          fw.rangeUpdate(len + 1, len + half, 2);
        }
      }
    }

    // case 4: a > y and b in the cycle
    if (y + 1 <= n) {
      for (int a = y + 1; a <= n; a++) {
        int len = a - y;
        if (cycle % 2 == 0) {
          int half = cycle / 2 - 1;
          fw.rangeUpdate(len, len, 1);
          fw.rangeUpdate(len + 1, len + half, 2);
          fw.rangeUpdate(len + half + 1, len + half + 1, 1);
        } else {
          int half = cycle / 2;
          fw.rangeUpdate(len, len, 1);
          fw.rangeUpdate(len + 1, len + half, 2);
        }
      }
    }

    // case 5: a < x and b > y
    if (x >= 2 and y + 1 <= n) {
      for (int a = x - 1; a >= 1; a--) {
        int len = x - a + 1; // a -> y
        int L = 1, R = n - y;
        fw.rangeUpdate(len + L, len + R, 1);
      }
    }

    for (int k = 1; k <= n; k++)
      ans[k - 1] += fw.get(k);
    for (int64 &x : ans)
      x *= 2;
    return ans;
  }
};

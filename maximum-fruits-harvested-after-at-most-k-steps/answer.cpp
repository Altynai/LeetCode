template <class T> struct Fenwick {

  vector<T> c;
  int n;

  Fenwick(int _n) {
    c.resize(_n + 1);
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void update(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] += y;
  }

  T sum(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }
};

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int n = fruits.size();
    startPos += 1;
    for (auto &f : fruits)
      f[0] += 1;

    const int N = max(startPos, fruits[n - 1][0]);

    Fenwick<int> fw(N);
    for (auto &f : fruits)
      fw.update(f[0], f[1]);

    int ans = 0;
    // go left and then right
    for (int i = 0; i <= min(k, startPos); i++) {
      int l = max(1, startPos - i);
      int r = startPos;
      if (i * 2 < k)
        r = min(N, startPos + k - i * 2);
      ans = max(ans, fw.sum(r) - fw.sum(l - 1));
    }
    // go right and then left
    for (int i = 0; i <= min(k, N - startPos); i++) {
      int r = min(N, startPos + i);
      int l = startPos;
      if (i * 2 < k)
        l = max(1, startPos - (k - i * 2));
      ans = max(ans, fw.sum(r) - fw.sum(l - 1));
    }
    return ans;
  }
};

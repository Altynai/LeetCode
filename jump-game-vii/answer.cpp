struct fenwick {
#define T int
#define max_m 100005

  T c[max_m];
  int n;

  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void add(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] += y;
  }

  T sum(int x) {
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }
} fw;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    fw.init(n + 1);
    fw.add(1, 1);

    for (int i = 2; i <= n; i++) {
      if (s[i - 1] == '1')
        continue;
      int r = i - minJump;
      int l = max(1, i - maxJump);
      if (r < 1)
        continue;
      if (fw.sum(r) - fw.sum(l - 1) > 0)
        fw.add(i, 1);
    }
    return fw.sum(n) - fw.sum(n - 1) == 1;
  }
};

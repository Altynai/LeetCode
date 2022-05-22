struct RMQ {
  typedef int T;

  const static int N = 100002;
  const static int M = 17; // 2^M >= N

  T mi[N][M];

  void init(int n, const vector<T> &val) {
    for (int i = 1; i <= n; i++)
      mi[i][0] = val[i - 1];

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T getMin(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return min(mi[a][k], mi[b - (1 << k) + 1][k]);
  }
} rmq;

const int MOD = 1e9 + 7;
inline int add(int x, int y) { return (x + y) % MOD; }
inline int sub(int x, int y) { return add(x, MOD - y); }
inline int mul(int x, int y) { return 1LL * x * y % MOD; }

class Solution {
public:
  int totalStrength(vector<int> &s) {
    int n = s.size();
    vector<int> f(n + 1, 0); // prefix sum
    for (int i = 1; i <= n; i++)
      f[i] = add(f[i - 1], s[i - 1]);
    vector<int> g(n + 1, 0); // prefix sum of prefix sum array
    for (int i = 1; i <= n; i++)
      g[i] = add(g[i - 1], f[i]);

    rmq.init(n, s);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      // find left endpoint, min(s[left ... i]) >= s[i]
      int left = -1, val = s[i - 1];
      for (int l = 1, r = i; l <= r;) {
        int mid = (l + r) / 2;
        if (rmq.getMin(mid, i) == val)
          left = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      assert(left != -1);

      // find right endpoint, min(s[i + 1 .... right]) > s[i]
      int right = i;
      for (int l = i + 1, r = n; l <= r;) {
        int mid = (l + r) / 2;
        if (rmq.getMin(i + 1, mid) > val)
          right = mid, l = mid + 1;
        else
          r = mid - 1;
      }

      // total sum =
      // f[i] - f[i - 1]
      // f[i] - f[i - 2]
      // ...
      // f[i] - f[left - 1]
      //
      // f[i + 1] - f[i - 1]
      // ..
      // f[right] - f[left - 1]
      // ^speed up calculation with g and multiply by s[i] (i.e. range minimal)
      int left_cnt = i - left + 1;
      int right_cnt = right - i + 1;

      int subtrahend = sub(g[i - 1], (left >= 2 ? g[left - 2] : 0));
      int subtrahend_sum = mul(right_cnt, subtrahend);

      int minued = sub(g[right], g[i - 1]);
      int minued_sum = mul(left_cnt, minued);

      ans = add(ans, mul(val, sub(minued_sum, subtrahend_sum)));
    }
    return ans;
  }
};

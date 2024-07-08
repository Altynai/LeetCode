template <class T> class AndOp {
public:
  T operator()(T a, T b) { return a & b; }
};

// example usage:
// RMQ<int, MinOp<int>> rmq;
// rmq.init(v);
template <typename T, typename OpFunc> struct RMQ {

  const static int N = 100002;
  const static int M = 17; // 2^M >= N

  T val[N][M];
  OpFunc opFunc = OpFunc();

  void init(const vector<T> &_val) {
    int n = _val.size();
    for (int i = 0; i < n; i++) {
      val[i][0] = _val[i];
    }

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        val[i][j] = opFunc(val[i][j - 1], val[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T query(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return opFunc(val[a][k], val[b - (1 << k) + 1][k]);
  }
};

using int64 = long long;

class Solution {
public:
  long long countSubarrays(vector<int> &a, int k) {
    int n = a.size();
    RMQ<int, AndOp<int>> rmq;
    rmq.init(a);

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < k)
        continue;

      int x = -1, y = -1;
      for (int l = 0, r = i; l <= r;) {
        int mid = (l + r) / 2;
        int res = rmq.query(mid, i);
        if (res >= k) {
          if (res == k)
            x = mid;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      for (int l = 0, r = i; l <= r;) {
        int mid = (l + r) / 2;
        int res = rmq.query(mid, i);
        if (res <= k) {
          if (res == k)
            y = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
      if (x != -1)
        ans += y - x + 1;
    }
    return ans;
  }
};

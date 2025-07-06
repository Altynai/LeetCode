template <class T> class GcdOp {
public:
  T operator()(T a, T b) { return gcd(a, b); }
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

class Solution {
public:
  int minStable(vector<int> &a, int maxC) {
    // we can modify to 1 to break the current stable subarray
    int n = a.size();
    RMQ<int, GcdOp<int>> rmq;
    rmq.init(a);

    auto Test = [&](int len) -> bool {
      int cnt = 0;
      for (int i = 0; i < n;) {
        if (a[i] == 1) {
          i++;
          continue;
        }
        int j = min(i + len, n - 1);
        if (rmq.query(i, j) >= 2 and j - i + 1 == len + 1)
          cnt++, i = j + 1;
        else
          i++;
      }
      return cnt <= maxC;
    };

    int ans = 0;
    for (int l = 0, r = n; l <= r;) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

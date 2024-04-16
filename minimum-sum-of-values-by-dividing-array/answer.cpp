template <class T> class MinOp {
public:
  T operator()(T a, T b) { return min(a, b); }
};

template <class T> class AndOp {
public:
  T operator()(T a, T b) { return a & b; }
};

// example usage:
// RMQ<int, MinOp<int>> rmq;
// rmq.init(v, MinOp<int>());
template <typename T, typename OpFunc> struct RMQ {

  const static int N = 10002;
  const static int M = 14; // 2^M >= N

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
  int minimumValueSum(vector<int> &a, vector<int> &andValues) {
    // dp[i][k] = dp[j - 1][k - 1] + a[i] (a[j ..... i] = andValues[k])
    // j can only be chosen in a range => binary search

    int n = a.size(), m = andValues.size();

    RMQ<int, AndOp<int>> and_rmq;
    vector<int> b = {0};
    b.insert(b.end(), a.begin(), a.end());
    and_rmq.init(b);

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    RMQ<int, MinOp<int>> min_rmq;
    for (int k = 1; k <= m; k++) {
      min_rmq.init(dp);
      int want = andValues[k - 1];

      vector<int> ndp(n + 1, INT_MAX);
      for (int i = 1; i <= n; i++) {
        int val = a[i - 1];

        int L = -1;
        for (int l = 1, r = i; l <= r;) {
          int mid = (l + r) / 2;
          int got = and_rmq.query(mid, i);
          if (got >= want) {
            r = mid - 1;
            if (got == want)
              L = mid;
          } else
            l = mid + 1;
        }

        int R = -1;
        for (int l = 1, r = i; l <= r;) {
          int mid = (l + r) / 2;
          int got = and_rmq.query(mid, i);
          if (got <= want) {
            l = mid + 1;
            if (got == want)
              R = mid;
          } else
            r = mid - 1;
        }

        if (L != -1) {
          int got = min_rmq.query(L - 1, R - 1);
          if (got != INT_MAX)
            ndp[i] = min(ndp[i], got + val);
        }
      }

      swap(dp, ndp);
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
  }
};

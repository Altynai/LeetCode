struct RMQ {
  typedef int T;

  const static int N = 50002;
  const static int M = 16; // 2^M >= N

  T ma[N][M];

  void init(int n, const vector<T> &val) {
    for (int i = 0; i < n; i++) {
      ma[i][0] = val[i];
    }

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T getMax(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return max(ma[a][k], ma[b - (1 << k) + 1][k]);
  }

} rmq;

using int64 = long long;

class Solution {
public:
  int maximumRobots(vector<int> &a, vector<int> &b, long long budget) {
    int n = a.size();
    vector<int64> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + b[i];
    rmq.init(n, a);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int p = -1;
      for (int l = i, r = n - 1; l <= r;) {
        int mid = (l + r) / 2;
        int64 ma = rmq.getMax(i, mid);
        int64 sm = sum[mid + 1] - sum[i];
        int k = mid - i + 1;
        if (ma + sm * k <= budget)
          p = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      if (p != -1)
        ans = max(ans, p - i + 1);
    }
    return ans;
  }
};

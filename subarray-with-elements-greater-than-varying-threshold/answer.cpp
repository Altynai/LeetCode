struct RMQ {
  typedef int T;

  const static int N = 200002;
  const static int M = 18; // 2^M >= N

  T mi[N][M];

  void init(int n, const vector<T> &val) {
    for (int i = 0; i < n; i++) {
      mi[i][0] = val[i];
    }

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
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

class Solution {
public:
  int validSubarraySize(vector<int> &a, int threshold) {
    int n = a.size();
    rmq.init(n, a);

    for (int i = 0; i < n; i++) {
      int x = -1;
      for (int l = 0, r = i; l <= r;) {
        int mid = (l + r) / 2;
        if (rmq.getMin(mid, i) == a[i])
          x = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      int y = -1;
      for (int l = i, r = n - 1; l <= r;) {
        int mid = (l + r) / 2;
        if (rmq.getMin(i, mid) == a[i])
          y = mid, l = mid + 1;
        else
          r = mid - 1;
      }

      int len = y - x + 1;
      if (a[i] > threshold / len)
        return len;
    }
    return -1;
  }
};

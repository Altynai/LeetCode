struct RMQ {
  const static int N = 100002;
  const static int M = 17; // 2^M >= N

  int mi[N][M], ma[N][M];

  void init(int n, vector<int> &val) {
    for (int i = 0; i < n; i++)
      mi[i][0] = ma[i][0] = val[i];

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
        mi[i][j] = min(mi[i][j - 1], mi[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int getMax(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return max(ma[a][k], ma[b - (1 << k) + 1][k]);
  }

  int getMin(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return min(mi[a][k], mi[b - (1 << k) + 1][k]);
  }
} rmq;

class Solution {
public:
  int maxSumMinProduct(vector<int> &nums) {
    int n = nums.size();
    rmq.init(n, nums);

    vector<long long> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
      s[i] = s[i - 1] + nums[i - 1];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x = i;
      for (int l = 0, r = i; l <= r;) {
        int m = (l + r) >> 1;
        if (rmq.getMin(m, i) >= nums[i]) {
          x = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      int y = i;
      for (int l = i, r = n - 1; l <= r;) {
        int m = (l + r) >> 1;
        if (rmq.getMin(i, m) >= nums[i]) {
          y = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      ans = max(ans, (s[y + 1] - s[x]) * nums[i]);
    }
    return ans % 1000000007;
  }
};

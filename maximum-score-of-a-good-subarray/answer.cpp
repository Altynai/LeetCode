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
  int maximumScore(vector<int> &nums, int k) {
    int n = nums.size();
    rmq.init(n, nums);

    int ans = 0;
    for (int num : nums) {
      if (num > nums[k])
        continue;

      int a = k;
      for (int l = 0, r = k; l <= r;) {
        int m = (l + r) >> 1;
        if (rmq.getMin(m, k) >= num) {
          a = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      int b = k;
      for (int l = k, r = n - 1; l <= r;) {
        int m = (l + r) >> 1;
        if (rmq.getMin(k, m) >= num) {
          b = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      ans = max(ans, rmq.getMin(a, b) * (b - a + 1));
    }

    return ans;
  }
};

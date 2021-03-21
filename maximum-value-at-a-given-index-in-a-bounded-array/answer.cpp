class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    long long ans = -1;
    for (long long l = 1, r = maxSum; l <= r;) {
      long long m = (l + r) >> 1;
      long long sum = m;
      vector<long long> cnts = {index, n - 1 - index};
      for (long cnt : cnts) {
        if (cnt <= m - 1) {
          sum += (m - 1 + m - cnt) * cnt / 2;
        } else {
          sum += m * (m - 1) / 2;
          sum += cnt - (m - 1);
        }
      }
      if (sum <= maxSum) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};

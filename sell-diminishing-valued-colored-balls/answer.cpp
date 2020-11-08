class Solution {
public:
  int maxProfit(vector<int> &a, int m) {
    int n = a.size();

    int l = 0, r = *max_element(a.begin(), a.end()), p = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      long long total = 0;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] >= mid) {
          total += a[i] - mid;
          cnt++;
        }
      }
      // we could at least decrease every color to p
      if (total + cnt >= m) {
        p = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    int ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
      if (a[i] >= p) {
        int cnt = min(m, a[i] - p);
        ans += (1LL * (a[i] + a[i] - cnt + 1) * cnt / 2) % mod;
        ans %= mod;
        m -= cnt;
      }
    }
    if (m > 0) {
      ans += (1LL * m * p % mod);
      ans %= mod;
    }
    return ans;
  }
};

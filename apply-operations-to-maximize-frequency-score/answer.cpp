using int64 = long long;

class Solution {
public:
  int maxFrequencyScore(vector<int> &a, long long k) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<int64> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i - 1];

    auto Test = [&](int len) -> bool {
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        int64 cost = 0;
        if (len % 2 == 0) {
          int l = i + len / 2 - 1, r = i + len / 2;
          int64 middle = (a[l - 1] + a[r - 1]) / 2;
          cost += middle * len / 2 - (sum[l] - sum[i - 1]);
          cost += (sum[j] - sum[r - 1]) - middle * len / 2;
        } else {
          int l = i + len / 2;
          int64 middle = a[l - 1];
          cost += middle * len / 2 - (sum[l - 1] - sum[i - 1]);
          cost += (sum[j] - sum[l]) - middle * len / 2;
        }
        if (cost <= k)
          return 1;
      }
      return 0;
    };

    int ans = 1;
    for (int l = 1, r = n; l <= r;) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};

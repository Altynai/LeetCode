using int64 = long long;

class Solution {
public:
  long long minOperationsToMakeMedianK(vector<int> &a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<int64> sum(n, a[0]);
    for (int i = 1; i < n; i++)
      sum[i] = sum[i - 1] + a[i];

    auto GetSum = [&](int l, int r) -> int64 {
      return (l == 0 ? sum[r] : sum[r] - sum[l - 1]);
    };

    int64 ans = 0;
    int x = n / 2; // median
    int pos = lower_bound(a.begin(), a.end(), k) - a.begin();
    if (pos <= x) {
      // a[pos - 1] < k <= a[pos], a[pos + 1], ..... , a[x]
      // decrease a[pos ... x] to k
      int64 len = x - pos + 1;
      ans += GetSum(pos, x) - len * k;
    } else {
      // a[x], .... , a[pos - 1] < k <= a[pos]
      // increase a[x ... pos - 1] to k
      int64 len = pos - x;
      ans += len * k - GetSum(x, pos - 1);
    }
    return ans;
  }
};

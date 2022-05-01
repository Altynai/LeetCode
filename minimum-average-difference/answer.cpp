class Solution {
public:
  int minimumAverageDifference(vector<int> &a) {
    int n = a.size();
    long long lsum = 0, rsum = accumulate(a.begin(), a.end(), 0LL);
    long long best = LLONG_MAX;

    int idx = -1;
    for (int i = 1; i <= n; i++) {
      lsum += a[i - 1];
      rsum -= a[i - 1];

      long long lavg = lsum / i;
      long long ravg = (i == n ? 0LL : rsum / (n - i));
      long long diff = llabs(lavg - ravg);
      if (diff < best) {
        best = diff;
        idx = i;
      }
    }
    return idx - 1;
  }
};

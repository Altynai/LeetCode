class Solution {
public:
  long long maximumBeauty(vector<int> &a, long long k, int target, int full,
                          int partial) {
    sort(a.begin(), a.end());
    int completed = 0;
    while (a.size() and a.back() >= target)
      completed++, a.pop_back();

    long long base_beauty = 1LL * completed * full;
    int n = a.size();
    if (n == 0)
      return base_beauty;

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + a[i - 1];

    auto range_sum = [&](int l, int r) -> long long {
      l++, r++;
      return pref[r] - pref[l - 1];
    };

    long long ans = 0;
    auto update_ans = [&](int cnt_full, int cnt_partial) {
      long long got = 1LL * cnt_full * full + 1LL * cnt_partial * partial;
      ans = max(ans, got);
    };

    // complete all gardens
    if (k >= 1LL * n * target - range_sum(0, n - 1))
      update_ans(n, 0);

    // complete some gardens
    for (int i = 0; i < n; i++) {
      // can we set the minimum to x for a[0, n - 1 - i]?
      // and a[n - i, n - 1] is completed
      long long used = 0;
      if (i)
        used += 1LL * i * target - range_sum(n - i, n - 1);
      if (used > k)
        break;

      int min_f = -1, j = n - 1 - i;
      for (int l = a[0], r = target - 1; l <= r;) {
        int mid = (l + r) / 2;
        int pos = lower_bound(a.begin(), a.begin() + j + 1, mid) - a.begin();
        if (pos == 0) {
          min_f = mid;
          l = mid + 1;
        } else {
          // set a[0, ... pos - 1] to mid
          long long need = 1LL * pos * mid - range_sum(0, pos - 1);
          if (need + used <= k) {
            min_f = mid;
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
      }
      update_ans(i, min_f);
    }
    return ans + base_beauty;
  }
};

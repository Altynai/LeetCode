using int64 = long long;

class Solution {
public:
  int64 maximumSubarraySum(vector<int> &a, int k) {
    int n = a.size(), m = *max_element(a.begin(), a.end());
    vector<int> cnt(m + 1, 0);

    int uniq = 0;
    int64 ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (cnt[a[i]]++ == 0)
        uniq++;
      if (i >= k) {
        cnt[a[i - k]]--;
        sum -= a[i - k];
        if (cnt[a[i - k]] == 0)
          uniq--;
      }
      if (i >= k - 1 and uniq == k)
        ans = max(ans, sum);
    }
    return ans;
  }
};

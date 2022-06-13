class Solution {
public:
  long long countSubarrays(vector<int> &a, long long k) {
    int n = a.size();
    vector<long long> psum(n + 1, 0);
    for (int i = 0; i < n; i++)
      psum[i + 1] = psum[i] + a[i];

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (k <= a[i - 1])
        continue;
      int j = -1;
      for (int l = 1, r = i; l <= r;) {
        int mid = (l + r) / 2;
        if ((psum[i] - psum[mid - 1]) * (i - mid + 1) < k)
          j = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      ans += i - j + 1;
    }
    return ans;
  }
};

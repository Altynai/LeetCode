class Solution {
public:
  int findKthNumber(int n, int m, int k) {
    int ans = -1;
    for (int l = 1, r = n * m; l <= r;) {
      int mid = (l + r) / 2, cnt = 0;
      for (int i = 1; i <= n; i++)
        cnt += min(m, mid / i);
      if (cnt >= k)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

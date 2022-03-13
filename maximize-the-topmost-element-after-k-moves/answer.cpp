class Solution {
public:
  int maximumTop(vector<int> &a, int k) {
    int n = a.size();
    if (k == 0)
      return a[0];
    else if (k == 1)
      return (n == 1 ? -1 : a[1]);

    // 2 <= k <= n
    if (k <= n) {
      int ans = (k == n ? -1 : a[k]);
      sort(a.begin(), a.begin() + k - 1);
      return max(ans, a[k - 2]);
    }

    int ans = -1, mx = -1;
    for (int i = 0; i < n; i++) {
      // if we only remove [0, i]
      mx = max(a[i], mx);
      int x = (k - i - 1);
      if (x & 1)
        ans = max(ans, mx);
      else {
        assert(x >= 2);
        // y1, y2, y3, .... ym
        // add y1, add ym, remove ym ... add ym
        if (i >= 1)
          ans = max(ans, mx);
      }
    }
    return ans;
  }
};

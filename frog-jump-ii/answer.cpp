class Solution {
public:
  int maxJump(vector<int> &a) {
    int n = a.size(), ans = -1;
    vector<bool> vis(n);
    for (int l = 1, r = a[n - 1]; l <= r;) {
      vis.assign(n, 0);
      int mid = (l + r) / 2, x = 0;

      bool ok = 1;
      // forward
      for (int i = 0; ok and i < n;) {
        int j = i + 1, nxt = -1;
        while (j < n and a[j] <= x + mid)
          nxt = j++;
        if (nxt == -1)
          ok = 0;
        else {
          i = nxt;
          vis[i] = 1;
          x = a[i];
          if (i == n - 1)
            break;
        }
      }
      // backward
      for (int i = n - 1; ok and i >= 0;) {
        int j = i - 1, nxt = -1;
        while (j >= 0 and x - mid <= a[j]) {
          if (!vis[j])
            nxt = j;
          j--;
        }
        if (nxt == -1)
          ok = 0;
        else {
          i = nxt;
          vis[i] = 1;
          x = a[i];
          if (i == 0)
            break;
        }
      }

      if (ok)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

class Solution {
public:
  int minimizeMax(vector<int> &a, int p) {
    if (p == 0)
      return 0;

    int n = a.size();
    sort(a.begin(), a.end());

    int ans = INT_MAX;
    for (int l = 0, r = a[n - 1] - a[0]; l <= r;) {
      int mid = (l + r) / 2;
      int cnt = 0;
      for (int i = 0, j = 1; i < n - 1;) {
        if (a[j] - a[i] <= mid)
          cnt++, i = j + 1;
        else
          i = j;
        j = i + 1;
      }
      if (cnt >= p)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

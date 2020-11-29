class Solution {
public:
  int minimumMountainRemovals(vector<int> &a) {
    int n = a.size();
    vector<int> l(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] > a[j])
          l[i] = max(l[i], l[j] + 1);
      }
    }

    vector<int> r(n, 1);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (a[i] > a[j])
          r[i] = max(r[i], r[j] + 1);
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (l[i] >= 2 && r[i] >= 2)
        ans = max(ans, l[i] + r[i] - 1);
    }
    return n - ans;
  }
};

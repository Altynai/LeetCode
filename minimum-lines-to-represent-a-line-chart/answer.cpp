class Solution {
public:
  int minimumLines(vector<vector<int>> &a) {
    sort(a.begin(), a.end());

    int n = a.size();
    if (n == 1)
      return 0;

    int ans = 1;
    for (int i = 2; i < n; i++) {
      int y1 = a[i - 1][1] - a[i - 2][1];
      int x1 = a[i - 1][0] - a[i - 2][0];

      int y2 = a[i][1] - a[i - 1][1];
      int x2 = a[i][0] - a[i - 1][0];

      if (1LL * y1 * x2 != 1LL * y2 * x1)
        ans++;
    }
    return ans;
  }
};

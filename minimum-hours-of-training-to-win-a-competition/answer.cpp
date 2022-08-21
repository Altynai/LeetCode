class Solution {
public:
  int minNumberOfHours(int x, int y, vector<int> &a, vector<int> &b) {
    int n = a.size(), xadd = 0, yadd = 0;
    for (int i = 0; i < n; i++) {
      if (x <= a[i])
        xadd += a[i] + 1 - x, x = a[i] + 1;
      x -= a[i];
      if (y <= b[i])
        yadd += b[i] + 1 - y, y = b[i] + 1;
      y += b[i];
    }
    return xadd + yadd;
  }
};

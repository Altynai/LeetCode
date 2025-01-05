using int64 = long long;

class Solution {
public:
  int maxLength(vector<int> &a) {
    int n = a.size(), ans = 1;
    for (int i = 0; i < n; i++) {
      int64 p = 1;
      int g = 0, l = 1;
      for (int j = i; j < n; j++) {
        g = gcd(g, a[j]);
        l = lcm(l, a[j]);
        p *= a[j];
        if (g * l == p)
          ans = max(ans, j - i + 1);
        else if (p > INT_MAX)
          break;
      }
    }
    return ans;
  }
};

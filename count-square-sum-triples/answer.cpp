class Solution {
public:
  int countTriples(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        int s = i * i + j * j;
        int r = sqrt(1.0 * s);
        if (r <= n && r * r == s)
          ans++;
      }
    }
    return ans;
  }
};

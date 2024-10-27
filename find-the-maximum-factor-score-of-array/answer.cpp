using int64 = long long;

class Solution {
public:
  long long maxScore(vector<int> &a) {
    int n = a.size();
    int64 l = a[0], g = 0;
    for (int i = 0; i < n; i++)
      l = lcm(l, a[i]), g = gcd(g, a[i]);

    int64 ans = l * g;
    for (int i = 0; i < n; i++) {
      l = 1, g = 0;
      for (int j = 0; j < n; j++) {
        if (j == i)
          continue;
        l = lcm(l, a[j]), g = gcd(g, a[j]);
      }
      ans = max(ans, l * g);
    }
    return ans;
  }
};

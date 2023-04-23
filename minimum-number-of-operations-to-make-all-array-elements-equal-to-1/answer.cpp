class Solution {
public:
  int minOperations(vector<int> &a) {
    int n = a.size();
    int g = a[0];
    for (int i = 1; i < n; i++)
      g = gcd(a[i], g);
    if (g > 1)
      return -1;

    int cnt = count(a.begin(), a.end(), 1);
    if (cnt > 0)
      return n - cnt;

    // does not have 1, but gcd = 1
    int ans = INT_MAX;
    for (int i = 0; i + 1 < n; i++) {
      int val = a[i];
      for (int j = i + 1; j < n; j++) {
        val = gcd(val, a[j]);
        if (val == 1) {
          ans = min(ans, (j - i) + n - 1);
          break;
        }
      }
    }
    return ans;
  }
};

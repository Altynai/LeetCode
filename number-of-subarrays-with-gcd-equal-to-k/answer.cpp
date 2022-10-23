class Solution {
public:
  int subarrayGCD(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      int g = a[i];
      for (int j = i; j < n and g >= k; j++) {
        g = gcd(a[j], g);
        if (g == k)
          ans++;
      }
    }
    return ans;
  }
};

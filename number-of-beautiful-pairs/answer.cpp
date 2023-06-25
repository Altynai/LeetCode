class Solution {
public:
  int countBeautifulPairs(vector<int> &a) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x = a[i];
      while (x >= 10)
        x /= 10;

      for (int j = i + 1; j < n; j++) {
        if (gcd(x, a[j] % 10) == 1)
          ans++;
      }
    }
    return ans;
  }
};

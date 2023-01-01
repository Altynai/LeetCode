class Solution {
public:
  int countDigits(int n) {
    int ans = 0;
    for (int x = n; x > 0; x /= 10) {
      if (n % (x % 10) == 0)
        ans++;
    }
    return ans;
  }
};

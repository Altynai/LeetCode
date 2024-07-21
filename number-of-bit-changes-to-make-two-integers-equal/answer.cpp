class Solution {
public:
  int minChanges(int n, int k) {
    if (n < k)
      return -1;

    int ans = 0;
    while (n > 0 and k > 0) {
      int x = n % 2, y = k % 2;
      n /= 2, k /= 2;
      if (x == y)
        continue;
      if (x == 1 and y == 0)
        ans++;
      else
        return -1;
    }
    while (n > 0) {
      ans += n % 2;
      n /= 2;
    }
    return ans;
  }
};

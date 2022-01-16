class Solution {
public:
  int minMoves(int n, int m) {
    int ans = 0;
    while (n > 1 && m > 0) {
      if (n % 2 == 0)
        n /= 2, m--;
      else
        n--;
      ans++;
    }
    return ans + n - 1;
  }
};

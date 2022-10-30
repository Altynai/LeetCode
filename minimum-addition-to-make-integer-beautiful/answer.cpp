using int64 = long long;

class Solution {
public:
  int cal(int64 n) {
    int ans = 0;
    while (n > 0)
      ans += n % 10, n /= 10;
    return ans;
  }

  int64 makeIntegerBeautiful(int64 n, int target) {
    int64 base = 1, ans = 0;
    while (cal(n) > target) {
      while (n % 10 == 0)
        base *= 10, n /= 10;
      n++, ans += base;
    }
    return ans;
  }
};

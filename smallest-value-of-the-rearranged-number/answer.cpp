class Solution {
public:
  long long smallestNumber(long long num) {
    if (num == 0)
      return 0;

    vector<int> c(10, 0);
    bool neg = num < 0;

    num = abs(num);
    while (num > 0)
      c[num % 10]++, num /= 10;

    long long x = 0;
    if (neg) {
      for (int i = 9; i >= 0; i--) {
        while (c[i]--)
          x = x * 10 + i;
      }
      x = -x;
    } else {
      bool check0 = true;
      for (int i = 1; i <= 9; i++) {
        while (c[i]--) {
          x = x * 10 + i;
          if (check0) {
            while (c[0]--)
              x = x * 10;
            check0 = false;
          }
        }
      }
    }
    return x;
  }
};

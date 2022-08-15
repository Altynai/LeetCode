#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int countSpecialNumbers(int n) {
    if (n < 10)
      return n;

    // mask: picked digits
    // len: targert length
    // ok: can start with 0
    auto count = [](int mask, int len, bool ok) -> int {
      if (len <= 0)
        return 1;

      int cnt = 0;
      for (int i = 1; i <= 9; i++)
        if (!bit(mask, i))
          cnt++;
      int zero = (bit(mask, 0) ? 0 : 1);
      if (cnt + zero < len)
        return 0;

      int ans = (ok ? cnt + zero : cnt);
      cnt = cnt + zero - 1;
      for (int i = 2; i <= len; i++) {
        assert(cnt >= 1);
        ans *= cnt, cnt--;
      }
      return ans;
    };

    int ans = 0, mask = 0;
    string s = to_string(n + 1);
    int m = s.size();
    for (int i = 0; i < m; i++) {
      int x = s[i] - '0';
      if (i == 0) {
        for (int len = 1; len < m; len++)
          ans += count(mask, len, len == 1);
        for (int y = 1; y < x; y++) {
          if (!bit(mask, y))
            ans += count(mask | (1 << y), m - 1, true);
        }
      } else {
        for (int y = 0; y < x; y++) {
          if (!bit(mask, y))
            ans += count(mask | (1 << y), m - 1 - i, true);
        }
      }

      if (bit(mask, x))
        break;
      mask |= (1 << x);
    }
    // 0 is not valid
    return ans - 1;
  }
};

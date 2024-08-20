class Solution {
public:
  string largestPalindrome(int n, int k) {
    if (n == 1)
      return string(1, '0' + (9 / k * k));

    // n >= 2
    if (k == 1 or k == 3 or k == 9)
      return string(n, '9');
    if (k == 2)
      return "8" + string(n - 2, '9') + "8";
    if (k == 4) {
      if (n <= 4)
        return string(n, '8');
      return "88" + string(n - 4, '9') + "88";
    }
    if (k == 5)
      return "5" + string(n - 2, '9') + "5";
    if (k == 6) {
      if (n == 2)
        return "66";

      // can be divided by 2 (choose 8 at both endpoints) and 3
      string s = "8" + string(n - 2, '9') + "8";
      int mod = ((n - 2) * 9 + 16) % 3;
      if (mod == 1) {
        if (n & 1)
          s[n / 2] -= 1;
        else
          s[n / 2] -= 2, s[n / 2 - 1] -= 2;
      } else if (mod == 2) {
        if (n & 1)
          s[n / 2] -= 2;
        else
          s[n / 2] -= 1, s[n / 2 - 1] -= 1;
      }
      return s;
    }

    if (k == 7) {
      if (n <= 2)
        return string(n, '7');

      string s(n, '9');
      if (n & 1) {
        int best = -1;
        for (int x = 9; best == -1 and x >= 0; x--) {
          int sum = 0;
          for (int i = 0; i < n; i++)
            sum = (sum * 10 + (i == n / 2 ? x : 9)) % 7;
          if (sum == 0)
            best = x;
        }
        s[n / 2] = '0' + best;
      } else {
        int best = -1;
        for (int x = 9; best == -1 and x >= 0; x--) {
          int sum = 0;
          for (int i = 0; i < n; i++)
            sum = (sum * 10 + (i == n / 2 or i == n / 2 - 1 ? x : 9)) % 7;
          if (sum == 0)
            best = x;
        }
        s[n / 2] = s[n / 2 - 1] = '0' + best;
      }
      return s;
    }

    // k = 8
    if (n <= 6)
      return string(n, '8');
    return "888" + string(n - 6, '9') + "888";
  }
};

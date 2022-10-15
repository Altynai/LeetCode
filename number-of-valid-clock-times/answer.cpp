class Solution {
public:
  int countTime(string s) {
    int ans = 0;
    for (int h = 0; h <= 23; h++) {
      int a = h / 10, b = h % 10;
      // no match
      if (s[0] != '?' and s[0] - '0' != a)
        continue;
      if (s[1] != '?' and s[1] - '0' != b)
        continue;

      for (int m = 0; m <= 59; m++) {
        int c = m / 10, d = m % 10;
        // no match
        if (s[3] != '?' and s[3] - '0' != c)
          continue;
        if (s[4] != '?' and s[4] - '0' != d)
          continue;
        ans++;
      }
    }
    return ans;
  }
};

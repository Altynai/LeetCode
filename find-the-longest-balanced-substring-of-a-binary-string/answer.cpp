class Solution {
public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0, n = s.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j += 2) {
        bool ok = 1;
        int len = j - i + 1;
        for (int k = i; ok and k < i + len / 2; k++)
          if (s[k] == '1')
            ok = 0;
        for (int k = i + len / 2; ok and k <= j; k++)
          if (s[k] == '0')
            ok = 0;
        if (ok)
          ans = max(ans, len);
      }
    }
    return ans;
  }
};

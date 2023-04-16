class Solution {
public:
  int addMinimum(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n;) {
      if (s[i] == 'a') {
        if (i + 1 < n and s[i + 1] == 'b') {
          // abc
          if (i + 2 < n and s[i + 2] == 'c')
            i += 3;
          // ab?
          else
            i += 2, ans++;
        }
        // ac?
        else if (i + 1 < n and s[i + 1] == 'c')
          i += 2, ans++;
        // aa?
        else
          i++, ans += 2;
      } else if (s[i] == 'b') {
        // bc?
        if (i + 1 < n and s[i + 1] == 'c')
          i += 2, ans++;
        // b?
        else
          i++, ans += 2;
      }
      // c?
      else
        i++, ans += 2;
    }
    return ans;
  }
};

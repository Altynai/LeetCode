class Solution {
public:
  string smallestBeautifulString(string s, int k) {
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
      int cur = s[i] - 'a';
      // try next char on position i
      for (int j = cur + 1; j < k; j++) {
        if (i >= 1 and s[i - 1] - 'a' == j)
          continue;
        if (i >= 2 and s[i - 2] - 'a' == j)
          continue;

        bool ok = true;
        // it's fine to make changes on s directly
        s[i] = 'a' + j;
        for (int p = i + 1; ok and p < n; p++) {
          int x = 0;
          for (; x < k; x++) {
            if (p >= 1 and s[p - 1] - 'a' == x)
              continue;
            if (p >= 2 and s[p - 2] - 'a' == x)
              continue;
            s[p] = 'a' + x;
            break;
          }
          if (x == k)
            ok = false;
        }
        if (ok)
          return s;
      }
    }
    return "";
  }
};

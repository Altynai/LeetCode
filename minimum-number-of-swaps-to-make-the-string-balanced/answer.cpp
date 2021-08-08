class Solution {
public:
  int minSwaps(string s) {
    int open = 0, close = 0, n = s.size(), ans = 0;
    for (int i = 0, j = n - 1; i < n; i++) {
      if (s[i] == '[')
        open++;
      else
        close++;

      if (close > open) {
        while (j >= 0 && s[j] == ']')
          j--;
        assert(j > i);
        swap(s[i], s[j]);
        open++;
        close--;
        ans++;
      }
    }
    return ans;
  }
};

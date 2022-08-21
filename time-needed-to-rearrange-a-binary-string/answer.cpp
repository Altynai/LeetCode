class Solution {
public:
  int secondsToRemoveOccurrences(string s) {
    int ans = 0, n = s.size();
    while (true) {
      bool ok = 0;
      for (int i = 1; i < n;) {
        if (s[i - 1] == '0' and s[i] == '1')
          swap(s[i - 1], s[i]), ok = 1, i += 2;
        else
          i++;
      }
      if (ok)
        ans++;
      else
        break;
    }
    return ans;
  }
};

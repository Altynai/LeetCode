class Solution {
public:
  int possibleStringCount(string s) {
    int n = s.size(), ans = 1;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and s[j] == s[i])
        j++;
      ans += j - i - 1;
      i = j;
    }
    return ans;
  }
};

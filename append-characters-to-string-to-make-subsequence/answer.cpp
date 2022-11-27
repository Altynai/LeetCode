class Solution {
public:
  int appendCharacters(string s, string t) {
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (j < m and i < n) {
      if (t[j] == s[i])
        j++, i++;
      else
        i++;
    }
    return m - j;
  }
};

class Solution {
public:
  int minimumLength(string s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
      if (s[i] != s[j])
        break;
      char ch = s[i];
      while (i <= j && s[i] == ch)
        i++;
      while (i <= j && s[j] == ch)
        j--;
    }
    if (i > j)
      return 0;
    return j - i + 1;
  }
};

class Solution {
public:
  int minimumBuckets(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'H') {
        if (i > 0 && s[i - 1] == 'X')
          continue;
        if (i + 1 < n && s[i + 1] == '.')
          s[i + 1] = 'X';
        else if (i > 0 && s[i - 1] == '.')
          s[i - 1] = 'X';
        else
          return -1;
      }
    }
    return count(s.begin(), s.end(), 'X');
  }
};

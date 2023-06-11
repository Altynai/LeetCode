class Solution {
public:
  string smallestString(string s) {
    int n = s.size(), pos = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] != 'a') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      s[n - 1] = 'z';
      return s;
    }

    for (int i = pos; i < n and s[i] != 'a'; i++)
      s[i]--;
    return s;
  }
};

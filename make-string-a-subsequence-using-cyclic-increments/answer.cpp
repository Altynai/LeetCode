class Solution {
public:
  bool canMakeSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    int j = 0;
    for (int i = 0; i < n and j < m; i++) {
      int x = s[i] - 'a';
      int y = t[j] - 'a';
      if (x == y || (x + 1) % 26 == y)
        j++;
    }
    return j == m;
  }
};

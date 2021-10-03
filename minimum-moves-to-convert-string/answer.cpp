class Solution {
public:
  int minimumMoves(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n;) {
      if (s[i] == 'X')
        i += 3, ans++;
      else
        i += 1;
    }
    return ans;
  }
};

class Solution {
public:
  int maxOperations(string s) {
    int ans = 0, moves = 0, n = s.size();
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == '1') {
        if (s[i + 1] == '1')
          ans += moves;
        else
          ans += (++moves);
      }
    }
    return ans;
  }
};

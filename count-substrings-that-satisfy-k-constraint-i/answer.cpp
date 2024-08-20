class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int one = count(s.begin() + i, s.begin() + j + 1, '1');
        if (one <= k or j - i + 1 - one <= k)
          ans++;
      }
    }
    return ans;
  }
};

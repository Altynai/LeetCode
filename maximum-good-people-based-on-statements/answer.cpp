#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int maximumGood(vector<vector<int>> &s) {
    int n = s.size(), ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      bool valid = 1;
      for (int i = 0; valid and i < n; i++) {
        for (int j = 0; valid and j < n; j++) {
          if (s[i][j] == 2)
            continue;
          else if (s[i][j] == 0) {
            if (bit(mask, i) and bit(mask, j))
              valid = 0;
          } else {
            if (bit(mask, i) and bit(mask, j) == 0)
              valid = 0;
          }
        }
      }
      if (valid)
        ans = max(ans, bitCount(mask));
    }
    return ans;
  }
};

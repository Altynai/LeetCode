#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int maximumRows(vector<vector<int>> &a, int cols) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    for (int i = 1; i < (1 << m); i++) {
      if (bitCount(i) == cols) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
          bool found = 1;
          for (int k = 0; found and k < m; k++) {
            if (a[j][k] == 1 and bit(i, k) == 0)
              found = 0;
          }
          if (found)
            cnt++;
        }
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};

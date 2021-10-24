#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int nextBeautifulNumber(int n) {
    int ans = INT_MAX, len = to_string(n).size();
    int m = len + 1;

    for (int mask = 1; mask < (1 << m); mask++) {
      string s;
      for (int i = 0; i < m; i++) {
        if (bit(mask, i))
          s += string(i + 1, '0' + i + 1);
      }
      if (s.size() < len || s.size() >= 8)
        continue;

      sort(s.begin(), s.end());
      do {
        int val = stoi(s);
        if (val > n) {
          ans = min(ans, val);
          break;
        }
      } while (next_permutation(s.begin(), s.end()));
    }
    return ans;
  }
};

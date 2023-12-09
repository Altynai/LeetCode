class Solution {
public:
  int removeAlmostEqualCharacters(string s) {
    int n = s.size(), ans = 0;
    for (int r = 0, l = 0; r < n;) {
      while (r + 1 < n and abs(s[r + 1] - s[r]) <= 1)
        r++;
      ans += (r - l + 1) / 2;
      l = ++r;
    }
    return ans;
  }
};

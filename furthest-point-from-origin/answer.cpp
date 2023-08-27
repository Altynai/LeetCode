class Solution {
public:
  int furthestDistanceFromOrigin(string s) {
    int l = 0, r = 0, n = s.size();
    for (char ch : s) {
      if (ch == 'L')
        l++;
      if (ch == 'R')
        r++;
    }
    return max(abs(n - l * 2), abs(n - r * 2));
  }
};

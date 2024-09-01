class Solution {
public:
  bool checkTwoChessboards(string s, string t) {
    int x = abs(s[0] - t[0]), y = abs(s[1] - t[1]);
    return (x & 1) == (y & 1);
  }
};

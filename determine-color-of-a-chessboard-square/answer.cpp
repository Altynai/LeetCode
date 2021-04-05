class Solution {
public:
  bool squareIsWhite(string s) {
    int a = (s[0] - 'a') & 1;
    int b = (s[1] - '0') & 1;
    return a == b;
  }
};

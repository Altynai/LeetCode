class Solution {
public:
  string removeTrailingZeros(string s) {
    while (s.size() > 1 and s.back() == '0')
      s.pop_back();
    return s;
  }
};

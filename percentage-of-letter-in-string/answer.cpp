class Solution {
public:
  int percentageLetter(string s, char letter) {
    return int(100.0 * count(s.begin(), s.end(), letter) / s.size());
  }
};

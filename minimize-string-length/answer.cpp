class Solution {
public:
  int minimizedStringLength(string s) {
    return set<char>(s.begin(), s.end()).size();
  }
};

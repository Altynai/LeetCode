class Solution {
public:
  bool checkIfPangram(string s) {
    return set<char>(s.begin(), s.end()).size() == 26;
  }
};

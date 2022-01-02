class Solution {
public:
  bool checkString(string s) {
    int n = count(s.begin(), s.end(), 'a');
    return string(n, 'a') == s.substr(0, n);
  }
};

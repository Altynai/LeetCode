class Solution {
public:
  string removeOccurrences(string s, string part) {
    int i = -1;
    while ((i = s.find(part)) != -1) {
      s = s.substr(0, i) + s.substr(i + part.size());
    }
    return s;
  }
};

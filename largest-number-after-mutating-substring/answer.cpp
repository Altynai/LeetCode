class Solution {
public:
  string maximumNumber(string s, vector<int> &change) {
    int n = s.size(), i = 0;
    while (i < n && s[i] - '0' >= change[s[i] - '0'])
      i++;
    while (i < n && s[i] - '0' <= change[s[i] - '0']) {
      s[i] = char('0' + change[s[i] - '0']);
      i++;
    }
    return s;
  }
};

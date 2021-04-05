class Solution {
public:
  string truncateSentence(string s, int k) {
    int spaces = count(s.begin(), s.end(), ' ');
    if (spaces <= k - 1)
      return s;

    int pos = -1;
    for (int i = 0; i < k; i++) {
      pos = s.find(' ', pos + 1);
    }
    return s.substr(0, pos);
  }
};

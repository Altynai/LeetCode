class Solution {
public:
  bool isAcronym(vector<string> &words, string s) {
    int n = words.size();
    if (s.size() != n)
      return 0;

    for (int i = 0; i < n; i++) {
      if (s[i] != words[i][0])
        return 0;
    }
    return 1;
  }
};

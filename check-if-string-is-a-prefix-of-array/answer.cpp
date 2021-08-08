class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    string ans = "";
    for (string word : words) {
      ans += word;
      if (s == ans)
        return 1;
    }
    return 0;
  }
};

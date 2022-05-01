class Solution {
public:
  string removeDigit(string s, char digit) {
    int n = s.size();
    string ans = "";
    for (int i = 0; i < n; i++)
      if (s[i] == digit) {
        string t = s.substr(0, i) + s.substr(i + 1);
        if (ans == "" or t > ans)
          ans = t;
      }
    return ans;
  }
};

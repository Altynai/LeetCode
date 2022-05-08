class Solution {
public:
  string largestGoodInteger(string s) {
    int n = s.size();
    string ans = "";
    for (int i = 0; i + 3 <= n; i++) {
      if (s[i] == s[i + 1] and s[i + 1] == s[i + 2]) {
        string t(3, s[i]);
        if (ans == "" or t > ans)
          ans = t;
      }
    }
    return ans;
  }
};

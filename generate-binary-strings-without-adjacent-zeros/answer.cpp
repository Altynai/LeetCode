class Solution {
public:
  vector<string> validStrings(int n) {
    vector<string> ans;

    function<void(string &, int)> dfs = [&](string &s, int pos) {
      if (pos == n) {
        ans.push_back(s);
        return;
      }
      s[pos] = '1';
      dfs(s, pos + 1);
      if (s[pos - 1] == '1') {
        s[pos] = '0';
        dfs(s, pos + 1);
      }
    };

    string s(n, '0');
    dfs(s, 1);
    s[0] = '1';
    dfs(s, 1);
    return ans;
  }
};

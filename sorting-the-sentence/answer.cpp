class Solution {
public:
  string sortSentence(string s) {
    istringstream iss(s);
    vector<string> tokens{istream_iterator<string>{iss},
                          istream_iterator<string>{}};
    int n = tokens.size();

    vector<string> ans(n);
    for (string token : tokens) {
      int m = token.size();
      int i = token[m - 1] - '0';
      ans[i - 1] = token.substr(0, m - 1);
    }

    stringstream ss;
    for (int i = 0; i < n; i++)
      ss << ans[i] << (i == n - 1 ? "" : " ");
    return ss.str();
  }
};

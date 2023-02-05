const string T = "aeiou";

class Solution {
  bool valid(const string &s) {
    return T.find(s[0]) != -1 and T.find(s.back()) != -1;
  }

public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    int n = words.size();
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + (valid(words[i - 1]) ? 1 : 0);
    }

    int m = queries.size();
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++)
      ans[i] = sum[queries[i][1] + 1] - sum[queries[i][0]];
    return ans;
  }
};

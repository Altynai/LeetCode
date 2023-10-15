class Solution {
public:
  vector<string> getWordsInLongestSubsequence(int n, vector<string> &words,
                                              vector<int> &groups) {
    auto dis = [&](int i, int j) -> int {
      int m = words[i].size();
      if (words[j].size() != m)
        return -1;

      int res = 0;
      for (int k = 0; k < m; k++)
        res += int(words[i][k] != words[j][k]);
      return res;
    };

    vector<int> dp(n, 1), prev(n, -1);
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (groups[j] == groups[i])
          continue;
        if (dis(i, j) != 1)
          continue;

        if (dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
    }

    vector<string> ans;
    int k = max_element(dp.begin(), dp.end()) - dp.begin();
    while (k != -1) {
      ans.push_back(words[k]);
      k = prev[k];
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

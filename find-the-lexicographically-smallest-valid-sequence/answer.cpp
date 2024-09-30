class Solution {
public:
  vector<int> validSequence(string word1, string word2) {
    int n = word1.size(), m = word2.size();

    // dp[i]: maximal suffix length matched of word2
    vector<int> dp(n + 1, 0);
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
      dp[i] = dp[i + 1];
      if (j >= 0 and word1[i] == word2[j])
        dp[i] += 1, j--;
    }

    vector<int> ans;
    bool changed = 0;
    for (int i = 0, j = 0; j < m and i < n; i++) {
      if (word1[i] == word2[j])
        ans.push_back(i), j++;
      // we can choose i if the rest is still enough
      else if (j + dp[i + 1] + 1 >= m and !changed)
        ans.push_back(i), j++, changed = 1;
    }
    return ans.size() == m ? ans : vector<int>();
  }
};

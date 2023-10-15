class Solution {
public:
  vector<string> getWordsInLongestSubsequence(int n, vector<string> &words,
                                              vector<int> &groups) {
    vector<vector<string>> ans(2);
    for (int i = 0; i < 2; i++) {
      int x = i;
      for (int j = 0; j < n; j++) {
        if (groups[j] == x) {
          ans[i].push_back(words[j]);
          x ^= 1;
        }
      }
    }
    return (ans[0].size() > ans[1].size() ? ans[0] : ans[1]);
  }
};

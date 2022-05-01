class Solution {
public:
  int countPrefixes(vector<string> &words, string s) {
    int ans = 0;
    for (auto &w : words)
      if (w == s.substr(0, w.size()))
        ans++;
    return ans;
  }
};

class Solution {
public:
  int countPrefixSuffixPairs(vector<string> &s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      int m = s[i].size();
      for (int j = i + 1; j < n; j++) {
        int k = s[j].size();
        if (m <= k and s[j].substr(0, m) == s[i] and s[j].substr(k - m) == s[i])
          ans++;
      }
    }
    return ans;
  }
};

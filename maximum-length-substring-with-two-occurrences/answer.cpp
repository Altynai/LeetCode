const int N = 26;

class Solution {
public:
  int maximumLengthSubstring(string s) {
    int n = s.size(), ans = 0;
    vector<int> cnt(N, 0);
    for (int i = 0, j = 0; i < n; i++) {
      while (j < n and cnt[s[j] - 'a'] <= 1)
        cnt[s[j++] - 'a']++;
      ans = max(ans, j - i);
      cnt[s[i] - 'a']--;
    }
    return ans;
  }
};

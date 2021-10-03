class Solution {
public:
  int maxConsecutiveAnswers(string s, int k) {
    int n = s.size(), ans = 0;
    vector<int> cnt(256, 0);
    for (int l = 0, r = 0; r < n; r++) {
      cnt[s[r]]++;
      while (min(cnt['T'], cnt['F']) > k)
        cnt[s[l++]]--;
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};

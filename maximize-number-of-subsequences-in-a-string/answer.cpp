class Solution {
public:
  long long maximumSubsequenceCount(string text, string pattern) {
    long long ans = 0;
    vector<int> cnt(2, 0);
    for (char ch : text) {
      if (ch == pattern[1])
        ans += cnt[0];

      if (ch == pattern[0])
        cnt[0]++;
      else if (ch == pattern[1])
        cnt[1]++;
    }
    ans += max(cnt[0], cnt[1]);
    return ans;
  }
};

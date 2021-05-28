class Solution {
public:
  int minSwaps(string s) {
    int n = s.size();
    auto cost = [&](char c) {
      vector<int> cnt(2, 0);
      int ans = 0;
      for (int i = 0; i < n; i++, c ^= 1) {
        if (s[i] == c)
          continue;
        cnt[s[i] - '0']++;
        cnt[c - '0']--;
        ans++;
      }
      return (ans % 2 == 0 && cnt[0] == 0 && cnt[1] == 0) ? ans / 2 : INT_MAX;
    };
    int ans = min(cost('0'), cost('1'));
    return ans == INT_MAX ? -1 : ans;
  }
};

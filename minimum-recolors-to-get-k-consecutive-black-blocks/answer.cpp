class Solution {
public:
  int minimumRecolors(string s, int k) {
    vector<int> cnt(2, 0);
    for (int i = 0; i < k; i++)
      cnt[s[i] == 'B']++;

    int ans = cnt[0], n = s.size();
    for (int i = k; i < n; i++) {
      cnt[s[i] == 'B']++;
      cnt[s[i - k] == 'B']--;
      ans = min(ans, cnt[0]);
    }
    return ans;
  }
};

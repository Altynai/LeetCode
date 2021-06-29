class Solution {
public:
  long long wonderfulSubstrings(string s) {
    int n = s.size();
    int m = *max_element(s.begin(), s.end()) - 'a' + 1;
    vector<int> cnt(1 << m, 0);
    cnt[0] = 1;

    int cur = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      cur ^= 1 << (s[i - 1] - 'a');
      // no odd values
      if (cnt[cur])
        ans += cnt[cur];
      // one odd value
      for (int j = 0; j < m; j++)
        ans += cnt[cur ^ (1 << j)];

      cnt[cur]++;
    }
    return ans;
  }
};

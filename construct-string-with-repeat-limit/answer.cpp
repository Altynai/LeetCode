class Solution {
public:
  string repeatLimitedString(string s, int m) {
    const int N = 26;
    vector<int> cnt(N, 0);
    for (char ch : s)
      cnt[ch - 'a']++;

    string ans;
    vector<int> now(N, 0);
    while (true) {
      int j = -1;
      for (int i = N - 1; j == -1 && i >= 0; i--) {
        if (cnt[i] && now[i] + 1 <= m)
          j = i;
      }
      if (j == -1)
        break;

      ans.push_back(char('a' + j));
      cnt[j]--, now[j]++;

      if (ans.size() >= m + 1) {
        int k = ans[ans.size() - m - 1] - 'a';
        now[k]--;
      }
    }
    return ans;
  }
};

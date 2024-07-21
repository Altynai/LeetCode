const int N = 26;

class Solution {
public:
  int minimumLength(string s) {
    vector<int> cnt(N, 0);
    for (char ch : s)
      cnt[ch - 'a']++;

    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (cnt[i] == 0)
        continue;
      if (cnt[i] % 2 == 0)
        ans += 2;
      else
        ans++;
    }
    return ans;
  }
};

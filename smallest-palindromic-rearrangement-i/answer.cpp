const int N = 26;

class Solution {
public:
  string smallestPalindrome(string s) {
    int n = s.size();
    vector<int> cnt(N, 0);
    for (char ch : s)
      cnt[ch - 'a']++;

    string ans(n, '*');
    int l = 0, r = n - 1;
    int odd = -1;
    for (int i = 0; i < N; i++) {
      if (cnt[i] == 0)
        continue;
      while (cnt[i] >= 2) {
        ans[l++] = ans[r--] = 'a' + i;
        cnt[i] -= 2;
      }
      if (cnt[i] == 1)
        odd = i;
    }
    if (odd != -1)
      ans[l] = 'a' + odd;
    return ans;
  }
};

const int N = 10;

class Solution {
public:
  string findValidPair(string s) {
    vector<int> cnt(N, 0);
    for (char ch : s)
      cnt[ch - '0']++;

    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1])
        continue;
      int x = s[i] - '0', y = s[i + 1] - '0';
      if (cnt[x] == x and cnt[y] == y)
        return s.substr(i, 2);
    }
    return "";
  }
};

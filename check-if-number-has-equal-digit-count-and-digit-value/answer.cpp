class Solution {
public:
  bool digitCount(string s) {
    vector<int> cnt(10, 0);
    for (char c : s)
      cnt[c - '0']++;

    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (cnt[i] != s[i] - '0')
        return 0;
    }
    return 1;
  }
};

class Solution {
public:
  long long countSubstrings(string s, char c) {
    int cnt = count(s.begin(), s.end(), c);
    return 1LL * cnt * (cnt - 1) / 2 + cnt;
  }
};

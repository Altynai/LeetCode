class Solution {
public:
  bool checkAlmostEquivalent(string s, string t) {
    int n = s.size();
    vector<int> cnt(26, 0);
    for (char ch : s)
      cnt[ch - 'a']++;
    for (char ch : t)
      cnt[ch - 'a']--;
    for (int i = 0; i < 26; i++)
      if (abs(cnt[i]) > 3)
        return 0;
    return 1;
  }
};

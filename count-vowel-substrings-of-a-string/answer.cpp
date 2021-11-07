class Solution {
public:
  int countVowelSubstrings(string s) {
    const string vowels = "aeiou";
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int j = i; j < n; j++) {
        int k = vowels.find(s[j]);
        if (k == -1)
          break;
        mask |= (1 << k);
        if (mask == 31)
          ans++;
      }
    }
    return ans;
  }
};

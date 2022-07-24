class Solution {
public:
  char repeatedCharacter(string s) {
    map<char, int> cnt;
    for (char c : s) {
      if (++cnt[c] == 2)
        return c;
    }
    return 'a';
  }
};

class Solution {
public:
  bool vowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
  }

  int vowelStrings(vector<string> &words, int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
      if (vowel(words[i][0]) and vowel(words[i].back()))
        ans++;
    }
    return ans;
  }
};

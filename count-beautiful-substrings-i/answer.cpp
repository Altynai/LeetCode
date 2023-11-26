const string VOWELS = "aeiou";

class Solution {
private:
  bool isVowel(char c) { return VOWELS.find(c) != -1; }

public:
  int beautifulSubstrings(string s, int k) {
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      int v = 0, c = 0;
      for (int j = i; j < n; j++) {
        if (isVowel(s[j]))
          v++;
        else
          c++;
        if (v == c and v * c % k == 0)
          ans++;
      }
    }
    return ans;
  }
};

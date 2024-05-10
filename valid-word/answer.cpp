class Solution {
  bool isVowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
  }

public:
  bool isValid(string s) {
    int n = s.size();
    if (n < 3)
      return 0;

    int vowel = 0, consonant = 0;
    for (int i = 0; i < n; i++) {
      char c = tolower(s[i]);
      if (!isdigit(c) and !islower(c) and !isupper(c))
        return 0;

      if (!isdigit(c)) {
        if (isVowel(c))
          vowel++;
        else
          consonant++;
      }
    }
    return vowel > 0 and consonant > 0;
  }
};

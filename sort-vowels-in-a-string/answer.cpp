class Solution {
private:
  bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  string sortVowels(string s) {
    string t = s;
    vector<int> vowels;
    for (char c : s) {
      if (isVowel(c))
        vowels.push_back(c);
    }

    sort(vowels.begin(), vowels.end());
    int i = 0;
    for (char &c : t) {
      if (isVowel(c))
        c = vowels[i++];
    }
    return t;
  }
};

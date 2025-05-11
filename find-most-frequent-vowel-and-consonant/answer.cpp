class Solution {
public:
  bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

  int maxFreqSum(string s) {
    unordered_map<char, int> v, c;
    int n = 0, m = 0;
    for (char ch : s) {
      if (isVowel(ch))
        n = max(n, ++v[ch]);
      else
        m = max(m, ++c[ch]);
    }
    return n + m;
  }
};

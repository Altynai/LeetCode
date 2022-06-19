const int N = 26;

class Solution {
public:
  string greatestLetter(string s) {
    vector<bool> lower(N), upper(N);
    for (char ch : s) {
      if (islower(ch))
        lower[ch - 'a'] = 1;
      else
        upper[ch - 'A'] = 1;
    }
    for (int i = N - 1; i >= 0; i--)
      if (lower[i] and upper[i])
        return string(1, 'A' + i);
    return "";
  }
};

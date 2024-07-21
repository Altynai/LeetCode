class Solution {
private:
  bool isVowel(char ch) {
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
  }

public:
  bool doesAliceWin(string s) {
    int cnt = 0;
    for (char ch : s) {
      if (isVowel(ch))
        cnt++;
    }
    return cnt > 0;
  }
};

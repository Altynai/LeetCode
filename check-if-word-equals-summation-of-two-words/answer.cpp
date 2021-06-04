class Solution {
public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    auto conv = [&](const string s) {
      int ans = 0, flag = 0;
      for (char ch : s) {
        if (ch == 'a') {
          if (flag)
            ans = ans * 10 + (ch - 'a');
        } else {
          flag = 1;
          ans = ans * 10 + (ch - 'a');
        }
      }
      return ans;
    };
    return conv(firstWord) + conv(secondWord) == conv(targetWord);
  }
};

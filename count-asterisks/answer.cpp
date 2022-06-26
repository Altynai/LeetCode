class Solution {
public:
  int countAsterisks(string s) {
    int ans = 0, cnt = 0;
    for (char ch : s) {
      if (ch == '|')
        cnt = (cnt + 1) % 2;
      else if (ch == '*' and cnt == 0)
        ans++;
    }
    return ans;
  }
};

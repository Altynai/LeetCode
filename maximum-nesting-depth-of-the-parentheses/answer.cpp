class Solution {
public:
  int maxDepth(string t) {
    int m = 0, ans = 0;
    for (char ch : t) {
      if (ch == '(')
        m++;
      if (ch == ')')
        m--;
      if (m > ans)
        ans = m;
    }
    return ans;
  }
};

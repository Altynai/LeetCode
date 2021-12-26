class Solution {
public:
  vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
    int m = s.size();
    vector<int> ans(m, 0);
    for (int i = m - 1; i >= 0; i--) {
      int x = startPos[0], y = startPos[1], j = i;
      for (; j < m; j++) {
        if (s[j] == 'U')
          x--;
        if (s[j] == 'D')
          x++;
        if (s[j] == 'L')
          y--;
        if (s[j] == 'R')
          y++;
        if (x < 0 or x >= n or y < 0 or y >= n)
          break;
      }
      ans[i] = j - i;
    }
    return ans;
  }
};

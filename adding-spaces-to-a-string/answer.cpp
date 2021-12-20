class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    int n = s.size();
    int m = spaces.size();
    string ans(n + m, ' ');
    for (int i = n - 1, p = n + m - 1, j = m - 1; i >= 0; i--) {
      ans[p--] = s[i];
      if (j >= 0 && i == spaces[j]) {
        ans[p--] = ' ';
        j--;
      }
    }
    return ans;
  }
};

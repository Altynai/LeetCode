class Solution {
public:
  bool placeWordInCrossword(vector<vector<char>> &a, string s) {
    int n = a.size(), m = a[0].size(), z = s.size();

    auto checkRow = [&](int i, int l, int r) -> bool {
      if (r - l + 1 != z)
        return 0;
      for (int j = l; j <= r; j++) {
        if (a[i][j] != ' ' && a[i][j] != s[j - l])
          return 0;
      }
      return 1;
    };

    auto checkColumn = [&](int j, int l, int r) -> bool {
      if (r - l + 1 != z)
        return 0;
      for (int i = l; i <= r; i++) {
        if (a[i][j] != ' ' && a[i][j] != s[i - l])
          return 0;
      }
      return 1;
    };

    for (int k = 0; k < 2; k++) {
      // check each row
      for (int i = 0; i < n; i++) {
        int l = 0, r = 0;
        while (l < m) {
          while (l < m && a[i][l] == '#')
            l++;
          r = l;
          while (r < m && a[i][r] != '#')
            r++;
          r--;
          if (r < m && checkRow(i, l, r))
            return 1;
          l = r + 1;
        }
      }

      // check each column
      for (int j = 0; j < m; j++) {
        int l = 0, r = 0;
        while (l < n) {
          while (l < n && a[l][j] == '#')
            l++;
          r = l;
          while (r < n && a[r][j] != '#')
            r++;
          r--;
          if (r < n && checkColumn(j, l, r))
            return 1;
          l = r + 1;
        }
      }

      reverse(s.begin(), s.end());
    }
    return 0;
  }
};

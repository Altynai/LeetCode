class Solution {
public:
  int minFlips(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size(), ans = 0;

    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < m / 2; j++) {
        vector<int> p(2, 0);
        p[a[i][j]]++;
        p[a[i][m - 1 - j]]++;
        p[a[n - 1 - i][j]]++;
        p[a[n - 1 - i][m - 1 - j]]++;
        ans += min(p[0], p[1]);
      }
    }

    int matched = 0;   // 1 and 1
    int unmatched = 0; // 0 and 1

    if (n % 2 == 1) {
      for (int j = 0; j < m / 2; j++) {
        if (a[n / 2][j] != a[n / 2][m - 1 - j])
          unmatched++;
        else if (a[n / 2][j] == 1)
          matched++;
      }
    }

    if (m % 2 == 1) {
      for (int i = 0; i < n / 2; i++) {
        if (a[i][m / 2] != a[n - 1 - i][m / 2])
          unmatched++;
        else if (a[i][m / 2] == 1)
          matched++;
      }
    }

    if (matched % 2 == 1) {
      if (unmatched == 0)
        ans += 2;
      else
        unmatched -= 1, ans++;
    }
    ans += unmatched;

    if (n % 2 == 1 and m % 2 == 1 and a[n / 2][m / 2] == 1)
      ans++;
    return ans;
  }
};

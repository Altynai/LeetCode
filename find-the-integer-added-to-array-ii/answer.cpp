class Solution {
public:
  int minimumAddedInteger(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto Test = [&](int x, int y) -> pair<bool, int> {
      int delta = 0;
      for (int j = 0, i = 0; j < m; j++) {
        while (i == x or i == y)
          i++;
        if (j == 0)
          delta = b[j] - a[i];
        else if (b[j] - a[i] != delta)
          return {false, 0};
        i++;
      }
      return {true, delta};
    };

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        auto [ok, val] = Test(i, j);
        if (ok)
          ans = min(ans, val);
      }
    }
    return ans;
  }
};

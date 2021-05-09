using ull = unsigned long long;

class Solution {
public:
  bool splitString(string s) {
    int n = s.size();

    function<bool(int, ull, ull)> dfs = [&](int j, ull now, ull need) -> bool {
      now = now * 10 + s[j] - '0';
      if (now > need)
        return 0;

      else if (now == need) {
        if (j == n - 1)
          return 1;
        // keep going
        if (j + 1 < n && dfs(j + 1, now, need))
          return 1;
        return j + 1 < n && dfs(j + 1, 0, need - 1);

      } else {
        return j + 1 < n && dfs(j + 1, now, need);
      }
    };

    ull need = 0;
    for (int i = 0; i < n - 1; i++) {
      need = need * 10 + s[i] - '0';

      if (dfs(i + 1, 0, need - 1))
        return 1;
    }
    return 0;
  }
};

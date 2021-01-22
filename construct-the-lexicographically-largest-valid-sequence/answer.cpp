class Solution {
public:
  vector<int> constructDistancedSequence(int n) {
    int m = n * 2 - 1;
    vector<int> p(m, -1);
    vector<bool> used(n + 1, 0);
    vector<int> ans;

    function<bool(int)> dfs = [&](int i) -> bool {
      while (i < m && p[i] != -1)
        i++;

      if (i == m) {
        ans = p;
        return 1;
      }

      for (int num = n; num >= 1; num--) {
        if (used[num])
          continue;

        if (num == 1) {
          used[num] = 1;
          p[i] = 1;

          if (dfs(i + 1))
            return 1;

          used[num] = 0;
          p[i] = -1;

        } else {
          if (i + num < m && p[i + num] == -1) {
            used[num] = 1;
            p[i] = p[i + num] = num;

            if (dfs(i + 1))
              return 1;

            used[num] = 0;
            p[i] = p[i + num] = -1;
          }
        }
      }
      return 0;
    };

    dfs(0);
    return ans;
  }
};

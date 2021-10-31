const int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

class Solution {
public:
  int countCombinations(vector<string> &names, vector<vector<int>> &pos) {
    int n = names.size();
    vector<int> dir(n), seconds(n);

    int ans = 0;
    function<void(int)> dfs = [&](int i) {
      if (i == n) {
        int time = *max_element(seconds.begin(), seconds.end()) + 1;
        for (int t = 0; t < time; t++) {
          bool vis[9][9] = {0};
          for (int j = 0; j < n; j++) {
            int x = pos[j][0] + dx[dir[j]] * min(seconds[j], t);
            int y = pos[j][1] + dy[dir[j]] * min(seconds[j], t);
            if (vis[x][y])
              return;
            vis[x][y] = 1;
          }
        }
        ans += 1;
        return;
      }

      int l = 0, r = 4;
      if (names[i] == "queen")
        r = 8;
      else if (names[i] == "bishop")
        l = 4, r = 8;

      // don't move
      dir[i] = l, seconds[i] = 0;
      dfs(i + 1);

      // move
      for (int k = l; k < r; k++) {
        dir[i] = k;
        int x = pos[i][0] + dx[k], y = pos[i][1] + dy[k], t = 1;
        while (1 <= x && x <= 8 && 1 <= y && y <= 8) {
          seconds[i] = t;
          dfs(i + 1);
          x += dx[k];
          y += dy[k];
          t += 1;
        }
      }
    };

    dfs(0);
    return ans;
  }
};

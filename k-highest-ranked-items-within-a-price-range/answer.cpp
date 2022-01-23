const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>> &g,
                                          vector<int> &pricing,
                                          vector<int> &start, int k) {
    int n = g.size(), m = g[0].size();

    vector<vector<int>> ans;
    vector<vector<int>> dis(n, vector<int>(m, -1));
    int x = start[0], y = start[1];
    deque<int> dq = {x, y};
    dis[x][y] = 0;
    if (pricing[0] <= g[x][y] and g[x][y] <= pricing[1])
      ans.push_back({x, y});

    while (dq.size()) {
      x = dq.front();
      dq.pop_front();
      y = dq.front();
      dq.pop_front();

      for (int p = 0; p < 4; p++) {
        int x2 = x + dx[p], y2 = y + dy[p];
        if (!inside(n, m, x2, y2) or g[x2][y2] == 0 or dis[x2][y2] != -1)
          continue;

        dis[x2][y2] = dis[x][y] + 1;
        dq.push_back(x2);
        dq.push_back(y2);
        if (pricing[0] <= g[x2][y2] and g[x2][y2] <= pricing[1])
          ans.push_back({x2, y2});
      }
    }

    sort(ans.begin(), ans.end(), [&](const auto &lh, const auto &rh) {
      if (dis[lh[0]][lh[1]] != dis[rh[0]][rh[1]])
        return dis[lh[0]][lh[1]] < dis[rh[0]][rh[1]];
      if (g[lh[0]][lh[1]] != g[rh[0]][rh[1]])
        return g[lh[0]][lh[1]] < g[rh[0]][rh[1]];
      if (lh[0] != rh[0])
        return lh[0] < rh[0];
      return lh[1] < rh[1];
    });

    while (ans.size() > k)
      ans.pop_back();
    return ans;
  }
};

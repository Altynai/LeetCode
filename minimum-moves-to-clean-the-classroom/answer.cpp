#define bit(n, i) (((n) >> (i)) & 1)

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int minMoves(vector<string> &a, int energy) {
    int n = a.size(), m = a[0].size();

    int cnt = 0, sx = -1, sy = -1;
    vector<vector<int>> ids(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'L')
          ids[i][j] = cnt++;
        else if (a[i][j] == 'S')
          sx = i, sy = j;
      }
    }
    if (cnt == 0)
      return 0;

    // x, y, mask, energy, steps
    using State = array<int, 5>;
    vector<vector<vector<int>>> best_energy(
        n, vector<vector<int>>(m, vector<int>(1 << cnt, -1)));

    queue<State> que;
    que.push({sx, sy, 0, energy, 0});
    int ans = INT_MAX;
    while (!que.empty()) {
      auto [x, y, mask, e, steps] = que.front();
      que.pop();
      if (mask == (1 << cnt) - 1)
        umin(ans, steps);
      if (e == 0)
        continue;

      for (int k = 0; k < 4; k++) {
        int x2 = x + dx[k], y2 = y + dy[k];
        if (!inside(n, m, x2, y2))
          continue;
        else if (a[x2][y2] == 'X')
          continue;
        else if (a[x2][y2] != 'L') {
          // 'S', 'R', '.'
          int e2 = (a[x2][y2] == 'R' ? energy : e - 1);
          if (e2 > best_energy[x2][y2][mask]) {
            best_energy[x2][y2][mask] = e2;
            que.push({x2, y2, mask, e2, steps + 1});
          }
        } else {
          int id = ids[x2][y2];
          int mask2 = mask;
          if (bit(mask, id) == 0)
            mask2 = mask | (1 << id);
          int e2 = e - 1;
          if (e2 > best_energy[x2][y2][mask2]) {
            best_energy[x2][y2][mask2] = e2;
            que.push({x2, y2, mask2, e2, steps + 1});
          }
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

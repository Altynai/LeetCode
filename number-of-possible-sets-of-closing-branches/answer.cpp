#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads) {
    vector<vector<int>> d(n, vector<int>(n, -1));
    vector<bool> active(n, 0);

    auto isGood = [&](int mask) -> bool {
      for (int i = 0; i < n; i++) {
        active[i] = bit(mask, i);
        for (int j = 0; j < n; j++)
          d[i][j] = -1;
      }
      for (auto r : roads) {
        if (!active[r[0]] or !active[r[1]])
          continue;
        if (d[r[0]][r[1]] == -1 or r[2] < d[r[0]][r[1]])
          d[r[0]][r[1]] = d[r[1]][r[0]] = r[2];
      }

      for (int k = 0; k < n; k++) {
        if (!active[k])
          continue;
        for (int i = 0; i < n; i++) {
          if (!active[i])
            continue;
          for (int j = 0; j < n; j++) {
            if (!active[j])
              continue;
            if (d[i][k] == -1 or d[k][j] == -1)
              continue;
            int x = d[i][k] + d[k][j];
            if (d[i][j] == -1 or x < d[i][j])
              d[i][j] = d[j][i] = x;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        if (!active[i])
          continue;
        for (int j = 0; j < n; j++) {
          if (!active[j] or i == j)
            continue;
          if (d[i][j] == -1)
            return 0; // disconnected
          if (d[i][j] > maxDistance)
            return 0;
        }
      }
      return 1;
    };

    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      if (isGood(mask))
        ans++;
    }
    return ans;
  }
};

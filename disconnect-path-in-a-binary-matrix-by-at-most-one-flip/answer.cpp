class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    if (n == 1 and m == 1)
      return true;

    vector<vector<int>> prev(n, vector<int>(m, -1));

    auto BFS = [&]() {
      for (int i = 0; i < n; i++)
        prev[i].assign(m, -1);

      queue<pair<int, int>> q;
      q.push({0, 0});

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // down
        if (x + 1 < n and a[x + 1][y] == 1 and prev[x + 1][y] == -1) {
          prev[x + 1][y] = 0;
          q.push({x + 1, y});
        }
        // right
        if (y + 1 < m and a[x][y + 1] == 1 and prev[x][y + 1] == -1) {
          prev[x][y + 1] = 1;
          q.push({x, y + 1});
        }
      }
    };

    BFS();
    if (prev[n - 1][m - 1] == -1)
      return true;

    // reset path
    for (int x = n - 1, y = m - 1; x != 0 or y != 0;) {
      int px = x, py = y;
      if (prev[x][y] == 0)
        px--;
      else
        py--;
      assert(a[px][py] == 1);
      a[px][py] = 0;
      x = px, y = py;
    }

    BFS();
    return prev[n - 1][m - 1] == -1;
  }
};

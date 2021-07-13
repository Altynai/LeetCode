const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int nearestExit(vector<vector<char>> &a, vector<int> &e) {
    int n = a.size(), m = a[0].size(), ans = INT_MAX;
    vector<vector<int>> d(n, vector<int>(m, -1));
    int x = e[0], y = e[1];
    deque<pair<int, int>> q = {{x, y}};
    d[x][y] = 0;

    while (q.size()) {
      tie(x, y) = q.front();
      q.pop_front();
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && d[nx][ny] == -1 &&
            a[nx][ny] == '.') {
          d[nx][ny] = d[x][y] + 1;
          q.push_back({nx, ny});

          if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)
            umin(ans, d[nx][ny]);
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};

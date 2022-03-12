const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  int trapRainWater(vector<vector<int>> &h) {
    using pii = pair<int, int>;

    int n = h.size(), m = h[0].size();
    const int N = n * m;

    vector<bool> vis(N, 0);
    min_priority_queue<pii> que;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 or i == n - 1 or j == 0 or j == m - 1) {
          int u = i * m + j;
          que.push({h[i][j], u});
          vis[u] = 1;
        }
      }
    }

    int ans = 0;
    while (!que.empty()) {
      auto [val, pos] = que.top();
      que.pop();

      int i = pos / m, j = pos % m;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        int v = x * m + y;
        if (inside(n, m, x, y) and !vis[v]) {
          ans += max(0, h[i][j] - h[x][y]);
          umax(h[x][y], h[i][j]);
          que.push({h[x][y], v});
          vis[v] = 1;
        }
      }
    }
    return ans;
  }
};

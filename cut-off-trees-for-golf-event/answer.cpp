const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int cutOffTree(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int N = n * m;

    vector<vector<int>> g(N);
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0)
          continue;
        int u = m * i + j;
        if (a[i][j] > 1)
          order.emplace_back(a[i][j], u);
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (inside(n, m, x, y) and a[x][y] > 0) {
            int v = m * x + y;
            g[u].push_back(v);
            g[v].push_back(u);
          }
        }
      }
    }

    sort(order.begin(), order.end());
    int ans = 0, u = 0;
    vector<int> d(N);
    for (auto &[h, v] : order) {
      d.assign(N, INT_MAX);
      queue<int> que;
      que.push(u);
      d[u] = 0;

      while (!que.empty()) {
        int x = que.front();
        que.pop();
        if (x == v)
          break;
        for (int y : g[x]) {
          if (d[y] == INT_MAX) {
            que.push(y);
            d[y] = d[x] + 1;
          }
        }
      }

      if (d[v] == INT_MAX)
        return -1;
      ans += d[v];
      u = v;
    }
    return ans;
  }
};

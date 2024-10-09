class Solution {
public:
  vector<vector<int>> constructGridLayout(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
      sort(adj[i].begin(), adj[i].end()); // used for set_intersection later

    // edge case: single row
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 1) {
        vector<bool> vis(n, 0);
        vector<vector<int>> ans(1);
        for (int j = 0, u = i; j < n; j++) {
          ans[0].push_back(u);
          vis[u] = 1;
          for (int v : adj[u]) {
            if (!vis[v]) {
              u = v;
              break;
            }
          }
        }
        return ans;
      }
    }

    // count nodes with degree 3 and 4
    int three = 0, four = 0;
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 3)
        three++;
      if (adj[i].size() == 4)
        four++;
    }

    // if grid is P x Q
    // (P - 2) * (Q - 2) = four
    // 2(P - 2) + 2(Q - 2) = three
    // P + Q = three / 2 + 4

    int P, Q;
    for (P = 1; P <= n; P++) {
      Q = three / 2 + 4 - P;
      if (Q > 1 and (P - 2) * (Q - 2) == four)
        break;
    }

    unordered_set<int> used;
    vector<vector<int>> ans(P, vector<int>(Q, -1));

    auto Find = [&](int x, int sz) -> int {
      for (int y : adj[x]) {
        if (used.count(y) == 0 and adj[y].size() == sz)
          return y;
      }
      return -1;
    };
    auto Record = [&](int x, int y, int id) {
      ans[x][y] = id;
      used.insert(id);
    };

    // edge case: 2 rows
    if (P == 2) {
      // pre-fill (0, 0) (1, 0)
      for (int i = 0; i < n; i++) {
        if (adj[i].size() == 2) {
          int x = Find(i, 2);
          Record(0, 0, i);
          Record(1, 0, x);
          break;
        }
      }
      // then fill by columns from left to right
      for (int c = 1; c < Q; c++) {
        int expected = (c == Q - 1 ? 2 : 3);
        for (int r = 0; r < 2; r++) {
          int x = Find(ans[r][c - 1], expected);
          Record(r, c, x);
        }
      }
      return ans;
    }

    // general case: pre-fill (0, 0) and (0, 1)
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 2) {
        Record(0, 0, i);

        // Tricky Part: how to fill (0, 1)? Total nodes on that path is Q
        int x = adj[i][0], nodes = 2;
        while (x != -1 and adj[x].size() == 3) {
          nodes++;
          // for temporary tracking, need to be reset later
          used.insert(x);
          x = Find(x, 3);
        }

        used = {i};
        if (nodes == Q)
          Record(0, 1, adj[i][0]);
        else
          Record(0, 1, adj[i][1]);
        break;
      }
    }

    for (int r = 0; r < P; r++) {
      for (int c = 0; c < Q; c++) {
        if (ans[r][c] != -1)
          continue;

        if (r == 0) {
          int left = ans[r][c - 1];
          int expected = (c == Q - 1 ? 2 : 3);
          int x = Find(left, expected);
          assert(x != -1);
          Record(r, c, x);
        } else if (c == 0) {
          int up = ans[r - 1][c];
          int expected = (r == P - 1 ? 2 : 3);
          int x = Find(up, expected);
          assert(x != -1);
          Record(r, c, x);
        } else {
          int left = ans[r][c - 1];
          int up = ans[r - 1][c];
          vector<int> shared;
          set_intersection(adj[up].begin(), adj[up].end(), adj[left].begin(),
                           adj[left].end(), back_inserter(shared));
          for (int x : shared) {
            if (used.count(x) == 0) {
              Record(r, c, x);
              break;
            }
          }
        }
      }
    }
    return ans;
  }
};

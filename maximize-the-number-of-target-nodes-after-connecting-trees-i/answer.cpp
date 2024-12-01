class Solution {
private:
  vector<int> count(const vector<vector<int>> &edges, int k) {
    int m = edges.size();
    int n = m + 1;
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> dis(n, -1);
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
      dis.assign(n, -1);
      queue<int> que;
      que.push(i);
      dis[i] = 0;
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : adj[u]) {
          if (dis[v] == -1 and dis[u] < k) {
            dis[v] = dis[u] + 1;
            que.push(v);
          }
        }
      }
      res[i] = n - std::count(dis.begin(), dis.end(), -1);
    }
    return res;
  }

public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<int> cnt1 = count(edges1, k), cnt2 = count(edges2, k - 1);
    int best = *max_element(cnt2.begin(), cnt2.end());

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = cnt1[i] + (k > 0 ? best : 0);
    }
    return ans;
  }
};

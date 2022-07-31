class Solution {
public:
  int longestCycle(vector<int> &to) {
    int n = to.size();
    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
      if (to[i] != -1)
        deg[to[i]]++;
    }

    vector<bool> vis(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        q.push(i);
        vis[i] = 1;
      }
    }
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      if (to[x] != -1) {
        if (--deg[to[x]] == 0) {
          q.push(to[x]);
          vis[to[x]] = 1;
        }
      }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        int j = i, cnt = 0;
        while (j != -1 and !vis[j]) {
          vis[j] = 1;
          cnt++;
          j = to[j];
        }
        if (j == i)
          ans = max(cnt, ans);
      }
    }
    return ans;
  }
};

class Solution {
public:
  int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
    set<int> f(forbidden.begin(), forbidden.end());
    int n = 10000;
    vector<int> dis(n, INT_MAX);
    vector<bool> inq(n, 0);

    deque<int> dq;
    dis[0] = 0;
    inq[0] = 1;
    dq.push_back(0);

    while (dq.size()) {
      int u = dq.front();
      dq.pop_front();
      inq[u] = 0;

      // move forward
      int v = u + a;
      if (v < n && f.count(v) == 0 && dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        if (!inq[v]) {
          inq[v] = 1;
          dq.push_back(v);
        }
      }

      // move backword
      v = u - b;
      if (v >= 0 && f.count(v) == 0) {
        dis[v] = min(dis[v], dis[u] + 1);
        // move forward again
        v += a;
        if (v < n && f.count(v) == 0 && dis[v] > dis[u] + 2) {
          dis[v] = dis[u] + 2;
          if (!inq[v]) {
            inq[v] = 1;
            dq.push_back(v);
          }
        }
      }
    }
    return dis[x] == INT_MAX ? -1 : dis[x];
  }
};

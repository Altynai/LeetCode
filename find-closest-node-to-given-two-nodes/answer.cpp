class Solution {
public:
  int closestMeetingNode(vector<int> &to, int u, int v) {
    int n = to.size();

    vector<bool> vis(n, 0);
    vector<int> du(n, -1);
    for (int x = u, d = 0; x != -1 and !vis[x]; x = to[x]) {
      du[x] = d++;
      vis[x] = 1;
    }

    vis.assign(n, 0);
    vector<int> dv(n, -1);
    for (int x = v, d = 0; x != -1 and !vis[x]; x = to[x]) {
      dv[x] = d++;
      vis[x] = 1;
    }

    int d = -1, ans = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (du[i] != -1 and dv[i] != -1) {
        int val = max(du[i], dv[i]);
        if (d == -1 or val <= d) {
          ans = i;
          d = val;
        }
      }
    }
    return ans;
  }
}

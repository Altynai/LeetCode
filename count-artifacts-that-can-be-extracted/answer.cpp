class Solution {
public:
  int digArtifacts(int n, vector<vector<int>> &artifacts,
                   vector<vector<int>> &dig) {
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    for (auto &d : dig)
      vis[d[0]][d[1]] = 1;

    int ans = 0;
    for (auto &rec : artifacts) {
      int cnt = 0;
      for (int i = rec[0]; i <= rec[2]; i++) {
        for (int j = rec[1]; j <= rec[3]; j++) {
          if (vis[i][j])
            cnt++;
        }
      }
      if (cnt == (rec[2] - rec[0] + 1) * (rec[3] - rec[1] + 1))
        ans++;
    }
    return ans;
  }
};

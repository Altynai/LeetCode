class Solution {
public:
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> pos(1 << m, -1);
    for (int i = 0; i < n; i++) {
      int x = 0;
      for (int j = 0; j < m; j++)
        x |= (a[i][j] << (m - j - 1));
      if (pos[x] == -1)
        pos[x] = i;
    }
    if (pos[0] != -1)
      return {pos[0]};

    int mask = (1 << m) - 1;
    for (int i = 1; i < mask; i++) {
      if (pos[i] == -1)
        continue;
      for (int j = i + 1; j < mask; j++) {
        if (pos[j] == -1)
          continue;
        if (i & j)
          continue;
        return {min(pos[i], pos[j]), max(pos[i], pos[j])};
      }
    }
    return {};
  }
};

class Solution {
public:
  int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
    vector<vector<int>> rows(n), cols(n);
    for (auto b : buildings) {
      int x = b[0] - 1, y = b[1] - 1;
      rows[x].push_back(y);
      cols[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
      sort(rows[i].begin(), rows[i].end());
      sort(cols[i].begin(), cols[i].end());
    }

    int ans = 0;
    for (auto b : buildings) {
      int x = b[0] - 1, y = b[1] - 1;
      int pos =
          lower_bound(rows[x].begin(), rows[x].end(), y) - rows[x].begin();
      if (pos == 0 or pos + 1 == rows[x].size())
        continue;
      pos = lower_bound(cols[y].begin(), cols[y].end(), x) - cols[y].begin();
      if (pos == 0 or pos + 1 == cols[y].size())
        continue;
      ans++;
    }
    return ans;
  }
};

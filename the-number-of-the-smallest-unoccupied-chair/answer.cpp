class Solution {
public:
  int smallestChair(vector<vector<int>> &t, int targetFriend) {
    vector<array<int, 3>> p;
    int n = t.size();
    for (int i = 0; i < n; i++) {
      p.push_back({t[i][0], 1, i});
      p.push_back({t[i][1], -1, i});
    }
    sort(p.begin(), p.end());
    set<int> used;
    set<int> valid;
    map<int, int> ids;
    for (int i = 0; i <= n + 1; i++)
      valid.insert(i);

    int m = p.size();
    for (int i = 0; i < m; i++) {
      if (p[i][1] == -1) {
        int j = ids[p[i][2]];
        used.erase(j);
        valid.insert(j);
      } else {
        int j = *valid.begin();
        if (p[i][2] == targetFriend)
          return j;
        valid.erase(j);
        used.insert(j);
        ids[p[i][2]] = j;
      }
    }
    return -1;
  }
};

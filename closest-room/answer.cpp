class Solution {
public:
  vector<int> closestRoom(vector<vector<int>> &rooms,
                          vector<vector<int>> &queries) {
    set<int> ids;
    int n = rooms.size();
    for (auto &room : rooms) {
      ids.insert(room[0]);
      swap(room[0], room[1]);
    }
    sort(rooms.begin(), rooms.end());

    int m = queries.size();
    for (int i = 0; i < m; i++) {
      queries[i].push_back(i);
      swap(queries[i][0], queries[i][1]);
    }
    sort(queries.begin(), queries.end());

    vector<int> ans(m, -1);
    for (int i = 0, j = 0; i < m; i++) {
      while (j < n && rooms[j][0] < queries[i][0])
        ids.erase(rooms[j++][1]);

      int diff = INT_MAX, best = -1;
      int pid = queries[i][1];
      auto it = ids.lower_bound(pid);
      if (it != ids.end()) {
        diff = abs(*it - pid);
        best = *it;
      }
      if (it != ids.begin()) {
        it = prev(it);
        if (abs(*it - pid) <= diff) {
          diff = abs(*it - pid);
          best = *it;
        }
      }
      ans[queries[i][2]] = best;
    }
    return ans;
  }
};

class Solution {
public:
  vector<int> countPoints(vector<vector<int>> &points,
                          vector<vector<int>> &queries) {

    auto inside = [&](vector<int> &point, vector<int> &query) -> bool {
      int dx = abs(point[0] - query[0]);
      int dy = abs(point[1] - query[1]);
      int r = query[2];
      return dx * dx + dy * dy <= r * r;
    };

    int n = queries.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      for (auto &point : points) {
        if (inside(point, queries[i]))
          ans[i]++;
      }
    }
    return ans;
  }
};

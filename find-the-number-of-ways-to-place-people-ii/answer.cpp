class Solution {
public:
  int numberOfPairs(vector<vector<int>> &points) {
    int n = points.size();
    sort(points.begin(), points.end(), [](const auto &lh, const auto &rh) {
      if (lh[0] != rh[0])
        return lh[0] < rh[0];
      return lh[1] > rh[1];
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
      multiset<int> y_coordinates;
      int x0 = points[i][0], y0 = points[i][1];

      for (int j = i + 1; j < n;) {
        int k = j;
        while (k < n and points[k][0] == points[j][0]) {
          int y1 = points[k++][1];
          if (y1 <= y0)
            y_coordinates.insert(y1);
        }
        for (int q = j; q < k; q++) {
          int x1 = points[q][0], y1 = points[q][1];
          if (y1 > y0)
            continue;
          assert(x0 <= x1 and y0 >= y1);

          // check if there is another y1 <= y <= y0
          auto it = y_coordinates.lower_bound(y1);
          it++;
          y_coordinates.insert(y1);
          if (it == y_coordinates.end() or *it > y0)
            ans++;
        }

        j = k;
      }
    }
    return ans;
  }
};

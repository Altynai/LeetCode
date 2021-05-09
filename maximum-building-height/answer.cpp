// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>> &r) {
    r.push_back({1, 0});
    r.push_back({n, n - 1});
    sort(r.begin(), r.end());

    int m = r.size();
    // left -> right
    for (int i = 1; i < m; i++) {
      int d = abs(r[i][0] - r[i - 1][0]);
      umin(r[i][1], r[i - 1][1] + d);
    }

    // right -> left
    for (int i = m - 2; i >= 0; i--) {
      int d = abs(r[i][0] - r[i + 1][0]);
      umin(r[i][1], r[i + 1][1] + d);
    }

    int ans = 0;
    for (int i = 1; i < m; i++) {
      int left = r[i][0] - r[i - 1][0] - 1;
      int h = max(r[i][1], r[i - 1][1]);
      left -= abs(r[i][1] - h);
      left -= abs(r[i - 1][1] - h);
      umax(ans, h + (left + 1) / 2);
    }
    return ans;
  }
};

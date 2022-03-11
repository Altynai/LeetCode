class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>> &a) {
    int n = a.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) -> bool {
      if (a[x][1] != a[y][1])
        return a[x][1] < a[y][1];
      return a[x][0] > a[y][0];
    });

    int ans = 2, l = a[p[0]][1] - 1, r = a[p[0]][1];
    for (int i = 1; i < n; i++) {
      int x = a[p[i]][0], y = a[p[i]][1];
      if (r < x)
        l = y - 1, r = y, ans += 2;
      else if (l < x)
        l = r, r = y, ans++;
    }
    return ans;
  }
};

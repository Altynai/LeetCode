class Solution {
private:
  int best(vector<int> &p, int rem) {
    int n = p.size();
    if (rem == p[0])
      return p[n - 1] - p[1];
    else if (rem == p[n - 1])
      return p[n - 2] - p[0];
    return p[n - 1] - p[0];
  };

public:
  int minimumDistance(vector<vector<int>> &p) {
    int n = p.size();
    vector<int> a1(n), a2(n), a3(n), a4(n);
    for (int i = 0; i < n; i++) {
      int x = p[i][0], y = p[i][1];
      a1[i] = x + y;
      a2[i] = x - y;
      a3[i] = -x + y;
      a4[i] = -x - y;
    }

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(a3.begin(), a3.end());
    sort(a4.begin(), a4.end());

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int x = p[i][0], y = p[i][1];
      int res = best(a1, x + y);
      res = max(res, best(a2, x - y));
      res = max(res, best(a3, -x + y));
      res = max(res, best(a4, -x - y));
      ans = min(ans, res);
    }
    return ans;
  }
};

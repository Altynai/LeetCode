class Solution {
public:
  int earliestFullBloom(vector<int> &p, vector<int> &g) {
    int n = p.size();

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
      // simplified based on binary serach version:
      // assume the earliest possible day is fixed, we need to
      // plant the one with bigger growth cost first
      if (g[x] != g[y])
        return g[x] > g[y];
      // if growth time is same, we choose the bigger plant time first
      else
        return p[x] > p[y];
    });

    int day = 0, ans = 0;
    for (int j : idx) {
      day += p[j];
      ans = max(ans, day + g[j]);
    }
    return ans;
  }
};

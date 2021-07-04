class Solution {
public:
  int eliminateMaximum(vector<int> &d, vector<int> &s) {
    int n = d.size();
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y) {
      // d[x] / s[x] <= d[y] / s[y]
      return 1LL * d[x] * s[y] < 1LL * d[y] * s[x];
    });

    int ans = 0;
    for (int t = 0, j = 0; t < n; t++) {
      int k = j;
      while (k < n && 1LL * t * s[id[k]] >= d[id[k]])
        k++;

      if (k > j)
        break;
      ans++;
      j++;
    }
    return ans;
  }
};

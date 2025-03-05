class Solution {
public:
  int countArrays(vector<int> &original, vector<vector<int>> &bounds) {
    int n = original.size();
    int l = bounds[0][0], r = bounds[0][1];
    for (int i = 1; i < n; i++) {
      int delta = original[i] - original[i - 1];
      l += delta, r += delta;
      l = max(l, bounds[i][0]);
      r = min(r, bounds[i][1]);
      if (l > r)
        return 0;
    }
    return r - l + 1;
  }
};

class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int ans = 0, d = 0;
    for (auto dimension : dimensions) {
      int len = dimension[0], width = dimension[1];
      int val = len * len + width * width;
      if (val > d)
        d = val, ans = len * width;
      else if (val == d)
        ans = max(ans, len * width);
    }
    return ans;
  }
};

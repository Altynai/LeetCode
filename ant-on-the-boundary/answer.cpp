class Solution {
public:
  int returnToBoundaryCount(vector<int> &a) {
    int ans = 0, pos = 0;
    for (int x : a) {
      pos += x;
      if (pos == 0)
        ans++;
    }
    return ans;
  }
};

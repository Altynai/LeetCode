class Solution {
public:
  int maximumCount(vector<int> &a) {
    int x = 0, y = 0;
    for (int val : a) {
      if (val < 0)
        x++;
      else if (val > 0)
        y++;
    }
    return max(x, y);
  }
};

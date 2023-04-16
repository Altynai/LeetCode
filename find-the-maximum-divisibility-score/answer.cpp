class Solution {
public:
  int maxDivScore(vector<int> &a, vector<int> &b) {
    int ans = INT_MAX, cnt = -1;
    for (int x : b) {
      int c = 0;
      for (int y : a) {
        if (y % x == 0)
          c++;
      }
      if (c > cnt or (c == cnt and x < ans))
        ans = x, cnt = c;
    }
    return ans;
  }
};

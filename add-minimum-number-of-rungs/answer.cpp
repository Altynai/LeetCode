class Solution {
public:
  int addRungs(vector<int> &rungs, int dist) {
    int n = rungs.size(), now = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (rungs[i] > now + dist) {
        int d = rungs[i] - now;
        ans += (d % dist == 0 ? d / dist - 1 : d / dist);
      }
      now = rungs[i];
    }
    return ans;
  }
};

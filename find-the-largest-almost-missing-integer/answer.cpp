class Solution {
public:
  int largestInteger(vector<int> &a, int k) {
    int n = a.size(), ans = -1;
    for (int x : a) {
      int cnt = 0;
      for (int i = 0; i + k <= n; i++) {
        set<int> s(a.begin() + i, a.begin() + i + k);
        if (s.count(x))
          cnt++;
      }
      if (cnt == 1)
        ans = max(ans, x);
    }
    return ans;
  }
};

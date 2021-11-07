class Solution {
public:
  int minimizedMaximum(int n, vector<int> &a) {
    int m = a.size(), ans = -1;
    for (int l = 1, r = *max_element(a.begin(), a.end()); l <= r;) {
      int mid = (l + r) >> 1;
      int cnt = 0;
      for (int x : a)
        cnt += (x + mid - 1) / mid;
      if (cnt <= n) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};

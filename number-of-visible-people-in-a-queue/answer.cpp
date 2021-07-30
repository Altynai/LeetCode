class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &h) {
    int n = h.size();
    vector<int> ans(n, 0);
    vector<int> q = {h[n - 1]};
    for (int i = n - 2; i >= 0; i--) {
      int m = q.size(), p = -1;
      for (int l = 0, r = m - 1; l <= r;) {
        int mid = (l + r) >> 1;
        if (q[mid] > h[i]) {
          p = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      if (p == -1)
        ans[i] = m;
      else
        ans[i] = m - p;

      while (q.size() && h[i] > q.back())
        q.pop_back();
      q.push_back(h[i]);
    }
    return ans;
  }
};

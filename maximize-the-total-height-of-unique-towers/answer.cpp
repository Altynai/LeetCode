using int64 = long long;

class Solution {
public:
  long long maximumTotalSum(vector<int> &h) {
    sort(h.begin(), h.end());
    int64 ans = 0, now = h.back();
    int n = h.size();
    for (int i = n - 1; i >= 0; i--) {
      if (now >= h[i]) {
        now = h[i];
        ans += now, now--;
      } else if (now == 0)
        return -1;
      else
        ans += now, now--;
    }
    return ans;
  }
};

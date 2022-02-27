class Solution {
public:
  long long minimumTime(vector<int> &time, int n) {
    long long mt = *max_element(time.begin(), time.end());
    long long ans = LLONG_MAX;
    for (long long l = 1, r = mt * n; l <= r;) {
      long long m = 0, mid = (l + r) / 2;
      for (int x : time)
        m += mid / x;
      if (m >= n) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};

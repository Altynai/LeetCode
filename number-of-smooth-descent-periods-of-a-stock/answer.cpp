class Solution {
public:
  long long getDescentPeriods(vector<int> &a) {
    int n = a.size();
    int len = 1;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1] - 1) {
        len += 1;
      } else {
        ans += 1LL * len * (len + 1) / 2;
        len = 1;
      }
    }
    ans += 1LL * len * (len + 1) / 2;
    return ans;
  }
};

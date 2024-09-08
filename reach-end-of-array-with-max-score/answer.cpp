using int64 = long long;

class Solution {
public:
  long long findMaximumScore(vector<int> &a) {
    /*
    consider i < j, if a[i] >= a[j], then no need to jump to j
    so we always jump to the next bigger number
    */
    int n = a.size(), prev = 0;
    int64 ans = 1LL * a[0] * (n - 1), cur = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[prev]) {
        cur += 1LL * a[prev] * (i - prev);
        prev = i;
        ans = max(ans, cur + 1LL * a[i] * (n - 1 - i));
      }
    }
    return ans;
  }
};

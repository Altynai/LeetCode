class Solution {
public:
  long long subArrayRanges(vector<int> &a) {
    int n = a.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int ma = a[i], mi = a[i];
      for (int j = i - 1; j >= 0; j--) {
        ma = max(a[j], ma);
        mi = min(a[j], mi);
        ans += ma;
        ans -= mi;
      }
    }
    return ans;
  }
};

class Solution {
public:
  int minimumCost(int n, int m, vector<int> &hc, vector<int> &vc) {
    sort(hc.begin(), hc.end());
    sort(vc.begin(), vc.end());

    int ans = 0, hcnt = 1, vcnt = 1;
    for (int i = n - 2, j = m - 2; i >= 0 or j >= 0;) {
      // highest value is horizontal
      if (j < 0 or (i >= 0 and hc[i] >= vc[j])) {
        ans += hc[i--] * vcnt;
        hcnt++;
      } else {
        ans += vc[j--] * hcnt;
        vcnt++;
      }
    }
    return ans;
  }
};

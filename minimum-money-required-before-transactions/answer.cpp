using int64 = long long;

class Solution {
public:
  int64 minimumMoney(vector<vector<int>> &a) {
    int n = a.size();
    sort(a.begin(), a.end(), [](vector<int> &lh, vector<int> &rh) {
      int64 option1 = min(-lh[0], -lh[0] + lh[1] - rh[0]);
      int64 option2 = min(-rh[0], -rh[0] + rh[1] - lh[0]);
      if (option1 != option2)
        return option1 < option2;
      return lh[0] < rh[0];
    });

    int64 ans = 0, now = 0;
    for (int i = 0; i < n; i++) {
      now -= a[i][0];
      ans = min(ans, now);
      now += a[i][1];
    }
    return -ans;
  }
};

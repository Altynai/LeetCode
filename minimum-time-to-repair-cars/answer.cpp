using int64 = long long;

class Solution {
public:
  long long repairCars(vector<int> &ranks, int cars) {
    int n = ranks.size();
    sort(ranks.begin(), ranks.end());

    int64 l = 1, r = 1LL * ranks[n - 1] * cars * cars;
    int64 ans = LLONG_MAX;
    while (l <= r) {
      int64 mid = (l + r) / 2;
      int64 cnt = 0;
      for (int i = 0; i < n; i++)
        cnt += (int64)sqrt(mid / ranks[i]);

      if (cnt >= cars)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

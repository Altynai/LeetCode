using int64 = long long;

class Solution {
public:
  long long maximumPoints(vector<int> &a, int currentEnergy) {
    int n = a.size();
    sort(a.begin(), a.end());

    int64 points = 0, cur = currentEnergy;
    for (int i = n - 1; i >= 0; i--) {
      if (cur >= a[0]) {
        int64 cnt = cur / a[0];
        points += cnt;
        cur -= cnt * a[0];
      }
      if (points > 0)
        cur += a[i];
    }
    return points;
  }
};

class Solution {
public:
  int minCostSetTime(int startAt, int moveCost, int pushCost,
                     int targetSeconds) {

    auto cost = [&](const vector<int> &digits) -> int {
      int ans = 0, where = startAt;
      for (int x : digits) {
        if (x != where) {
          ans += moveCost;
          where = x;
        }
        ans += pushCost;
      }
      return ans;
    };

    int ans = INT_MAX;
    for (int m = 0; m <= 99; m++) {
      for (int s = 0; s <= 99; s++) {
        if (m * 60 + s != targetSeconds)
          continue;

        vector<int> digits = {m / 10, m % 10, s / 10, s % 10};
        ans = min(ans, cost(digits));
        while (digits.size() and digits[0] == 0) {
          digits.erase(digits.begin());
          ans = min(ans, cost(digits));
        }
      }
    }
    return ans;
  }
};

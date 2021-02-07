class Solution {
public:
  int minAbsDifference(vector<int> &nums, int goal) {
    int n = nums.size();
    if (n == 1) {
      return min(abs(goal), abs(nums[0] - goal));
    }

    // first half
    int x = (n + 1) / 2;

    // second half
    int y = n - x;
    vector<int> g(1 << y, 0);
    for (int i = 0; i < y; i++) {
      for (int mask = 1; mask < (1 << y); mask++) {
        if (mask & (1 << i))
          g[mask] += nums[x + i];
      }
    }

    set<int> second(g.begin(), g.end());
    int ans = abs(goal);
    for (int mask = 0; mask < (1 << x); mask++) {
      int val = 0;
      for (int i = 0; i < x; i++) {
        if (mask & (1 << i))
          val += nums[i];
      }

      // fisrt + second >= goal
      // second >= goal - first
      auto it = second.lower_bound(goal - val);
      if (it != second.end()) {
        ans = min(ans, abs(val + *it - goal));
      }

      // fisrt + second < goal
      // second < goal - first
      it = second.lower_bound(goal - val);
      if (it != second.begin()) {
        it = prev(it);
        ans = min(ans, abs(val + *it - goal));
      }
    }
    return ans;
  }
};

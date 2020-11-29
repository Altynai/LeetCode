class Solution {
public:
  int minMoves(vector<int> &nums, int limit) {
    int n = nums.size();
    int m = n / 2;
    int maxn = limit * 2;
    vector<int> s(maxn + 1, 0);

    auto update = [&](int l, int r, int val) {
      if (l > r)
        return;
      s[l] += val;
      if (r + 1 < maxn)
        s[r + 1] -= val;
    };

    for (int i = 0; i < m; i++) {
      int mi = min(nums[i], nums[n - 1 - i]);
      int ma = max(nums[i], nums[n - 1 - i]);
      // one move
      int l = mi + 1, r = ma + limit;
      update(l, mi + ma - 1, 1);
      update(mi + ma + 1, r, 1);
      // two moves
      update(2, l - 1, 2);
      update(r + 1, maxn, 2);
    }

    int ans = INT_MAX;
    for (int i = 2; i <= maxn; i++) {
      s[i] += s[i - 1];
      ans = min(ans, s[i]);
    }
    return ans;
  }
};

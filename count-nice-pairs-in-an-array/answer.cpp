class Solution {
public:
  int countNicePairs(vector<int> &nums) {
    auto rev = [&](int val) {
      while (val > 0 && val % 10 == 0)
        val /= 10;
      int ans = 0;
      while (val > 0) {
        ans = ans * 10 + val % 10;
        val /= 10;
      }
      return ans;
    };

    map<int, int> cnt;
    int ans = 0, MOD = 1e9 + 7;
    for (int num : nums) {
      int val = num - rev(num);
      if (cnt.count(val))
        ans = (ans + cnt[val]) % MOD;
      cnt[val]++;
    }
    return ans;
  }
};

using ll = long long;

class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size();

    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + nums[i - 1];

    ll removed = sum[n] - x;
    if (removed == 0)
      return n;

    unordered_map<ll, int> where;
    where[0] = 0;

    int len = -1;
    for (int i = 1; i <= n; i++) {
      auto it = where.find(sum[i] - removed);
      if (it != where.end())
        len = max(len, i - (it->second));

      if (where.count(sum[i]) == 0)
        where[sum[i]] = i;
    }
    return len == -1 ? -1 : n - len;
  }
};

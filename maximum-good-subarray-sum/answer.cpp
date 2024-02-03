using int64 = long long;

class Solution {
public:
  long long maximumSubarraySum(vector<int> &a, int k) {
    int n = a.size();
    vector<int64> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i - 1];

    unordered_map<int, int64> min_sum;
    int64 ans = 0;
    bool first = 1;

    auto Update = [&](int64 val) {
      if (first)
        ans = val, first = 0;
      else
        ans = max(ans, val);
    };

    for (int i = 1; i <= n; i++) {
      // query
      auto it = min_sum.find(a[i - 1] + k);
      if (it != min_sum.end())
        Update(sum[i] - (it->second));
      it = min_sum.find(a[i - 1] - k);
      if (it != min_sum.end())
        Update(sum[i] - (it->second));

      // update
      it = min_sum.find(a[i - 1]);
      if (it == min_sum.end())
        min_sum[a[i - 1]] = sum[i - 1];
      else
        min_sum[a[i - 1]] = min(sum[i - 1], min_sum[a[i - 1]]);
    }
    return ans;
  }
};

using int64 = long long;

class Solution {
public:
  long long maxSum(vector<int> &a, int m, int k) {
    int n = a.size();

    unordered_map<int, int> cnt;
    int uniq = 0;
    int64 ans = 0, sum = 0;

    auto Add = [&](int x) {
      if (cnt[x]++ == 0)
        uniq++;
      sum += x;
    };

    auto Remove = [&](int x) {
      if (--cnt[x] == 0)
        uniq--;
      sum -= x;
    };

    for (int i = 0; i < n; i++) {
      Add(a[i]);
      if (uniq >= m)
        ans = max(ans, sum);
      if (i >= k - 1)
        Remove(a[i - k + 1]);
    }
    return ans;
  }
};

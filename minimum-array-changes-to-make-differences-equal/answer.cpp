class Solution {
public:
  int minChanges(vector<int> &a, int k) {
    int n = a.size();

    vector<int> v(k + 1, 0);
    auto Add = [&](int l, int r, int val) {
      v[l] += val;
      if (r + 1 <= k)
        v[r + 1] -= val;
    };

    for (int i = 0; i < n / 2; i++) {
      int x = abs(a[i] - a[n - 1 - i]);
      // maximal range we can get with only 1 operation
      // rest will be 2 operations
      int y = max(max(a[n - 1 - i], abs(k - a[n - 1 - i])),
                  max(a[i], abs(k - a[i])));
      assert(x <= y);
      if (x > 0)
        Add(0, x - 1, +1);
      if (x < y)
        Add(x + 1, y, +1);
      if (y < k)
        Add(y + 1, k, +2);
    }

    int ans = v[0];
    for (int i = 1; i <= k; i++) {
      v[i] += v[i - 1];
      ans = min(ans, v[i]);
    }
    return ans;
  }
};

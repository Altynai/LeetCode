class Solution {
public:
  int minimizeSum(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());

    auto GetAns = [&](int l, int r) -> int {
      if (l >= r)
        return 0;
      return a[r] - a[l];
    };

    int ans = GetAns(0, n - 3);
    ans = min(ans, GetAns(1, n - 2));
    ans = min(ans, GetAns(2, n - 1));
    return ans;
  }
};

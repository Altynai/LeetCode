class Solution {
public:
  vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l,
                                        vector<int> &r) {
    int n = nums.size();

    auto check = [&](int x, int y) {
      if (y <= x + 1)
        return true;

      vector<int> a;
      for (int i = x; i <= y; i++)
        a.push_back(nums[i]);
      sort(a.begin(), a.end());

      int m = a.size(), d = a[1] - a[0];
      for (int i = 2; i < m; i++) {
        if (a[i] - a[i - 1] != d)
          return false;
      }
      return true;
    };

    vector<bool> ans;
    int m = l.size();
    for (int i = 0; i < m; i++) {
      ans.push_back(check(l[i], r[i]));
    }
    return ans;
  }
};

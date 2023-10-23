class Solution {
public:
  int minGroupsForValidAssignment(vector<int> &a) {
    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;
    vector<int> v;
    for (auto [x, cnt] : freq)
      v.push_back(cnt);

    int n = v.size(), ans = INT_MAX;
    sort(v.begin(), v.end());

    // minimal number of groups to split x numbers into groups of sizing either
    // "each" or "each + 1"
    auto minGroup = [&](int x, int each) -> int {
      int res = -1;
      for (int l = 1, r = (x + each - 1) / each; l <= r;) {
        int mid = (l + r) / 2;
        int sum = mid * each;
        if (sum > x)
          r = mid - 1;
        else if (x - sum <= mid)
          res = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      return res;
    };

    for (int i = 1; i <= v[0]; i++) {
      int cnt = 0;
      bool good = 1;
      for (int j = 0; good and j < n; j++) {
        int mg = minGroup(v[j], i);
        if (mg == -1)
          good = 0;
        else
          cnt += mg;
      }
      if (good)
        ans = min(ans, cnt);
    }
    return ans;
  }
};

class Solution {
public:
  vector<int> smallestTrimmedNumbers(vector<string> &nums,
                                     vector<vector<int>> &queries) {
    vector<int> ans;
    int n = nums.size(), m = nums[0].size();

    for (auto q : queries) {
      int len = q[1], k = q[0] - 1;
      vector<pair<string, int>> c;
      for (int i = 0; i < n; i++)
        c.push_back({nums[i].substr(m - len), i});
      sort(c.begin(), c.end());
      ans.push_back(c[k].second);
    }
    return ans;
  }
};

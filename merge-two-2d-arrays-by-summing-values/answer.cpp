class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    map<int, int> sum;
    for (auto x : nums1)
      sum[x[0]] += x[1];
    for (auto x : nums2)
      sum[x[0]] += x[1];

    vector<vector<int>> ans;
    for (auto [k, v] : sum)
      ans.push_back({k, v});
    return ans;
  }
};

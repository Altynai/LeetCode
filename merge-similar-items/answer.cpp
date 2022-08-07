class Solution {
public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {
    map<int, int> sum;
    for (auto item : items1)
      sum[item[0]] += item[1];
    for (auto item : items2)
      sum[item[0]] += item[1];
    vector<vector<int>> ans;
    for (auto [value, weight] : sum)
      ans.push_back({value, weight});
    return ans;
  }
};

class Solution {
public:
  vector<int> intersection(vector<vector<int>> &a) {
    map<int, int> cnt;
    for (auto &row : a)
      for (int x : row)
        cnt[x]++;

    vector<int> ans;
    for (auto [k, v] : cnt)
      if (v == a.size())
        ans.push_back(k);
    return ans;
  }
};

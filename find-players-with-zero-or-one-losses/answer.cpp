class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    map<int, int> cnt;
    for (auto &match : matches) {
      cnt[match[1]] += 1;
      cnt[match[0]] += 0;
    }
    vector<vector<int>> ans(2);
    for (auto [who, c] : cnt)
      if (c <= 1)
        ans[c].push_back(who);
    return ans;
  }
};

class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &a) {
    int n = 0;
    unordered_map<int, int> cnt;
    for (int x : a)
      n = max(n, ++cnt[x]);

    vector<vector<int>> ans(n);
    for (auto [k, v] : cnt) {
      for (int i = 0; i < v; i++)
        ans[i].push_back(k);
    }
    return ans;
  }
};

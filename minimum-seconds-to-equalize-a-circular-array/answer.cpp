class Solution {
public:
  int minimumSeconds(vector<int> &a) {
    int n = a.size();
    unordered_map<int, vector<int>> where;
    for (int i = 0; i < n; i++)
      where[a[i]].push_back(i);

    auto Count = [](int i, int j) -> int {
      int cnt = j - i - 1;
      return (cnt + 1) / 2;
    };

    int ans = INT_MAX;
    for (auto &[key, pos] : where) {
      int m = pos.size();
      int best = Count(pos[m - 1], n + pos[0]);
      for (int i = 0; i + 1 < m; i++)
        best = max(best, Count(pos[i], pos[i + 1]));
      ans = min(ans, best);
    }
    return ans;
  }
};

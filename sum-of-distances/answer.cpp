using int64 = long long;

class Solution {
public:
  vector<long long> distance(vector<int> &a) {
    int n = a.size();
    unordered_map<int, vector<int>> where;
    for (int i = 0; i < n; i++)
      where[a[i]].push_back(i);

    vector<int64> ans(n, 0);
    for (auto &[x, v] : where) {
      int m = v.size();
      int64 sum = 0, cnt = 0;
      for (int i = 0; i < m; i++) {
        int idx = v[i];
        ans[idx] += cnt * idx - sum;
        cnt++, sum += idx;
      }
      cnt = 0, sum = 0;
      for (int i = m - 1; i >= 0; i--) {
        int idx = v[i];
        ans[idx] += sum - cnt * idx;
        cnt++, sum += idx;
      }
    }
    return ans;
  }
};

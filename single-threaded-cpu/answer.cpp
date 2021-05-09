class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; i++)
      tasks[i].push_back(i);
    sort(tasks.begin(), tasks.end());

    long long now = tasks[0][0];
    vector<int> ans(n, -1);
    set<array<int, 2>> s;
    for (int i = 0, j = 0; i < n; i++) {
      if (s.empty() && now < tasks[j][0]) {
        assert(j < n);
        now = tasks[j][0];
      }
      while (j < n && tasks[j][0] <= now) {
        s.insert({tasks[j][1], tasks[j][2]});
        j++;
      }
      ans[i] = (*s.begin())[1];
      now += (*s.begin())[0];
      s.erase(s.begin());
    }
    return ans;
  }
};

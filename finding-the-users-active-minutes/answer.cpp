class Solution {
public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    vector<int> ans(k, 0);
    map<int, set<int>> cnt;
    for (auto &log : logs) {
      cnt[log[0]].insert(log[1]);
    }

    for (auto &[user, minutes] : cnt)
      ans[minutes.size() - 1]++;
    return ans;
  }
};

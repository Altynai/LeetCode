class Solution {
public:
  vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
    set<pair<int, int>> idle;    // weight, index
    set<pair<int, int>> running; // finishTime, index
    int n = servers.size(), m = tasks.size();
    for (int i = 0; i < n; i++)
      idle.emplace(servers[i], i);

    auto refresh = [&](int time) {
      while (!running.empty() && running.begin()->first <= time) {
        int j = running.begin()->second;
        running.erase(running.begin());
        idle.emplace(servers[j], j);
      }
    };

    vector<int> ans(m, -1);
    deque<int> q;
    for (int i = 0; i < m; i++) {
      q.push_back(i);
      refresh(i);

      while (!idle.empty() && !q.empty()) {
        int k = q.front();
        q.pop_front();

        int j = idle.begin()->second;
        idle.erase(idle.begin());
        running.emplace(i + tasks[k], j);
        ans[k] = j;
      }
    }

    int time = m;
    while (!q.empty()) {
      int k = q.front();
      q.pop_front();
      refresh(time);
      if (idle.empty()) {
        assert(running.begin()->first > time);
        time = running.begin()->first;
        refresh(time);
      }

      int j = idle.begin()->second;
      idle.erase(idle.begin());
      running.emplace(time + tasks[k], j);
      ans[k] = j;
    }
    return ans;
  }
};

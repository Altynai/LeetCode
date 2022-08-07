class Solution {
public:
  long long taskSchedulerII(vector<int> &tasks, int space) {
    long long day = 0;
    int n = tasks.size();
    map<int, long long> last;
    for (int i = 0; i < n; i++) {
      auto it = last.find(tasks[i]);
      if (it == last.end())
        day++;
      else
        day = max(it->second + space + 1, day + 1);
      last[tasks[i]] = day;
    }
    return day;
  }
};

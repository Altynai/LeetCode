class TaskManager {
private:
  set<pair<int, int>> s;
  unordered_map<int, int> task2user;
  unordered_map<int, int> task2priority;

public:
  TaskManager(vector<vector<int>> &tasks) {
    for (auto task : tasks)
      add(task[0], task[1], task[2]);
  }

  void add(int userId, int taskId, int priority) {
    s.insert({priority, taskId});
    task2user[taskId] = userId;
    task2priority[taskId] = priority;
  }

  void edit(int taskId, int newPriority) {
    rmv(taskId);
    add(task2user[taskId], taskId, newPriority);
  }

  void rmv(int taskId) { s.erase({task2priority[taskId], taskId}); }

  int execTop() {
    if (s.empty())
      return -1;
    auto it = prev(s.end());
    auto [_, tid] = *it;
    s.erase(it);
    rmv(tid);
    return task2user[tid];
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

class LockingTree {
private:
  vector<int> p;
  vector<vector<int>> g;
  vector<int> locked;
  vector<int> size;
  int n;

public:
  LockingTree(vector<int> &p) {
    this->p = p;
    n = p.size();
    g = vector<vector<int>>(n, vector<int>());
    for (int i = 1; i < n; i++)
      g[p[i]].push_back(i);

    locked = vector<int>(n, -1);
    size = vector<int>(n, 0);
  }

  void update(int num) {
    while (num != -1) {
      size[num] = 0;
      for (int v : g[num])
        size[num] += size[v];
      if (locked[num] != -1)
        size[num]++;
      num = p[num];
    }
  }

  bool lock(int num, int user) {
    if (locked[num] == -1) {
      locked[num] = user;
      update(num);
      return true;
    }
    return false;
  }

  void unlockAll(int num) {
    locked[num] = -1;
    size[num] = 0;
    for (int v : g[num])
      unlockAll(v);
  }

  bool unlock(int num, int user) {
    if (locked[num] == -1)
      return false;
    if (locked[num] != user)
      return false;

    locked[num] = -1;
    update(num);
    return true;
  }

  bool upgrade(int num, int user) {
    /*
    The node is unlocked,
    It has at least one locked descendant (by any user), and
    It does not have any locked ancestors.
    */
    if (locked[num] != -1)
      return false;
    if (size[num] == 0)
      return false;

    int x = num;
    while (x != -1 && locked[x] == -1)
      x = p[x];
    if (x != -1)
      return false;

    locked[num] = user;
    for (int v : g[num])
      unlockAll(v);
    update(num);
    return true;
  }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */

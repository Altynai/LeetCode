class Allocator {
  int n;
  map<int, int> ids;

public:
  Allocator(int _n) {
    n = _n;
    ids[n] = -1; // always allocated
  }

  int allocate(int size, int mID) {
    for (int i = 0; i + size <= n; i++) {
      int x = ids.lower_bound(i)->first;
      if (x != i and i + size <= x) {
        for (int j = i; j < i + size; j++)
          ids[j] = mID;
        return i;
      }
    }
    return -1;
  }

  int free(int mID) {
    int cnt = 0;
    for (auto it = ids.begin(); it != ids.end();) {
      if (it->second == mID)
        it = ids.erase(it), cnt++;
      else
        it++;
    }
    return cnt;
  }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

struct fenwick {
#define T int
#define max_m 100005

  T c[max_m];
  int n;

  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void update(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] = std::max(c[x], y);
  }

  T max(int x) {
    T ret = 0;
    for (; x; x -= x & -x)
      ret = std::max(ret, c[x]);
    return ret;
  }
} fw;

class Solution {
public:
  int minOperations(vector<int> &target, vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> where;
    for (int i = 1; i <= n; i++)
      where[arr[i - 1]].push_back(i);

    fw.init(n);
    for (int t : target) {
      auto it = where.find(t);
      if (it != where.end()) {
        vector<int> &pos = it->second;
        int m = pos.size();
        for (int i = m - 1; i >= 0; i--) {
          int mx = fw.max(pos[i] - 1);
          fw.update(pos[i], mx + 1);
        }
      }
    }
    return target.size() - fw.max(n);
  }
};

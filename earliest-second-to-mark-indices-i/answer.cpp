template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  int earliestSecondToMarkIndices(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size(), ans = -1;
    for (int &index : b)
      index--;

    auto Test = [&](int k) -> int {
      vector<int> c = a, last(n, -1);
      for (int i = k; i >= 0; i--) {
        if (last[b[i]] == -1)
          last[b[i]] = i;
      }
      for (int i = 0; i < n; i++) {
        if (last[i] == -1)
          return 0;
      }

      vector<bool> marked(n, 0);
      // last[i], index i
      // because we want to greedily decrease the c[i] who has the lower last[i]
      min_priority_queue<pair<int, int>> que;
      for (int i = 0; i < n; i++)
        que.push({last[i], i});
      for (int i = 0; i <= k; i++) {
        // have to mark the current index
        if (last[b[i]] == i and !marked[b[i]]) {
          if (c[b[i]] > 0)
            return 0;
          marked[b[i]] = 1;
        } else if (!que.empty()) {
          int j = que.top().second;
          que.pop();
          if (c[j] > 0) {
            if (--c[j] > 0)
              que.push({last[j], j});
          } else if (!marked[j]) {
            marked[j] = 1;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        if (!marked[i])
          return 0;
      }
      return 1;
    };

    for (int l = 0, r = m - 1; l <= r;) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid + 1, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};

using int64 = long long;

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
    min_priority_queue<pair<int, int>> que;
    for (auto p : conflictingPairs) {
      que.push({max(p[0], p[1]), min(p[0], p[1])});
    }

    int64 ans = 0;
    map<pair<int, int>, int64> gains;
    for (int i = 1; i <= n; i++) {
      while (!que.empty() and que.top().second < i)
        que.pop();
      int r = n + 1;
      if (!que.empty())
        r = que.top().first;
      ans += r - i;

      if (!que.empty()) {
        auto p = que.top();
        que.pop();

        while (!que.empty() and que.top().second < i)
          que.pop();
        int r2 = n + 1;
        if (!que.empty())
          r2 = que.top().first;

        gains[p] += r2 - r;
        que.push(p);
      }
    }

    int64 best = 0;
    for (auto [_, v] : gains)
      umax(best, v);
    return ans + best;
  };
};

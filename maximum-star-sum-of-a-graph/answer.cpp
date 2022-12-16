template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

struct State {
  int k, sum;
  min_priority_queue<int> q;

  State() {}
  State(int _k) { k = _k, sum = 0; }

  int update(int x) {
    if (q.size() == k and k > 0) {
      int y = q.top();
      q.pop();
      if (y >= 0)
        sum -= y;
    }
    q.push(x);
    if (q.size() <= k and x >= 0)
      sum += x;
    return sum;
  }
};

class Solution {
public:
  int maxStarSum(vector<int> &a, vector<vector<int>> &edges, int k) {
    int n = a.size();
    vector<State> s(n, State(k));
    vector<int> ans(n, 0);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      ans[u] = max(ans[u], s[u].update(a[v]));
      ans[v] = max(ans[v], s[v].update(a[u]));
    }

    int best = INT_MIN;
    for (int i = 0; i < n; i++)
      best = max(best, ans[i] + a[i]);
    return best;
  }
};

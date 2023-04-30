template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minimumCost(vector<int> &start, vector<int> &target,
                  vector<vector<int>> &roads) {
    int n = roads.size();
    int ans = abs(start[0] - target[0]) + abs(start[1] - target[1]);

    vector<int> dis(n, INT_MAX);
    min_priority_queue<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
      dis[i] = abs(start[0] - roads[i][0]) + abs(start[1] - roads[i][1]);
      dis[i] += roads[i][4];
      que.push({dis[i], i});
    }

    while (!que.empty()) {
      auto [d, i] = que.top();
      que.pop();

      for (int j = 0; j < n; j++) {
        int cost = d;
        cost += abs(roads[i][2] - roads[j][0]) + abs(roads[i][3] - roads[j][1]);
        cost += roads[j][4];
        if (cost < dis[j])
          que.push({dis[j] = cost, j});
      }
    }

    for (int i = 0; i < n; i++)
      umin(ans, dis[i] + abs(target[0] - roads[i][2]) +
                    abs(target[1] - roads[i][3]));
    return ans;
  }
};

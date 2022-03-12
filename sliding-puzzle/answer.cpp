template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &a) {
    using State = array<int, 6>;
    const State dest = {1, 2, 3, 4, 5, 0};

    map<State, int> dis;
    min_priority_queue<pair<int, State>> q;
    auto tryAddQueue = [&](int d, const State &s) {
      auto it = dis.find(s);
      if (it == dis.end() or d < it->second) {
        dis[s] = d;
        q.push({d, s});
      }
    };

    State source = {a[0][0], a[0][1], a[0][2], a[1][0], a[1][1], a[1][2]};
    tryAddQueue(0, source);

    while (!q.empty()) {
      auto [d, cur] = q.top();
      q.pop();
      if (cur == dest)
        return d;

      int i = 0;
      while (cur[i] != 0)
        i++;
      // up & down
      if (i >= 3) {
        State nxt = cur;
        swap(nxt[i], nxt[i - 3]);
        tryAddQueue(d + 1, nxt);
      } else {
        State nxt = cur;
        swap(nxt[i], nxt[i + 3]);
        tryAddQueue(d + 1, nxt);
      }
      // left
      if (i % 3 >= 1) {
        State nxt = cur;
        swap(nxt[i], nxt[i - 1]);
        tryAddQueue(d + 1, nxt);
      }
      // right
      if (i % 3 <= 1) {
        State nxt = cur;
        swap(nxt[i], nxt[i + 1]);
        tryAddQueue(d + 1, nxt);
      }
    }
    return -1;
  }
};

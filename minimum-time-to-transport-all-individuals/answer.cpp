#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool umax(T &a, const T b) { return b > a ? a = b, 1 : 0; }

class Solution {
public:
  double minTime(int n, int k, int m, vector<int> &time, vector<double> &mul) {
    // state = mask (people at dest), position (0: camp, 1: dest), stage
    using State = array<int, 3>;
    using Node = pair<double, State>;

    map<State, double> dis;
    priority_queue<Node, vector<Node>, greater<Node>> q;

    State start = {0, 0, 0};
    dis[start] = 0.0;
    q.push({0.0, start});

    while (!q.empty()) {
      auto [d, state] = q.top();
      q.pop();
      // skip invalid node
      if (dis[state] != d)
        continue;

      auto [mask, position, stage] = state;
      if (position == 0) {
        // select a sub-group
        int people = ((1 << n) - 1) ^ mask;
        for (int sub = people; sub > 0; sub = (sub - 1) & people) {
          int cnt = bitCount(sub);
          if (cnt > k)
            continue;

          int t = 0;
          for (int i = 0; i < n; i++) {
            if (bit(sub, i))
              umax(t, time[i]);
          }

          double cost = mul[stage] * t;
          double new_dis = d + cost;
          State new_state = {mask ^ sub, 1, (stage + (int)floor(cost) % m) % m};
          if (dis.find(new_state) == dis.end() or new_dis < dis[new_state]) {
            dis[new_state] = new_dis;
            q.push({new_dis, new_state});
          }
        }
      } else {
        // someone goes back
        for (int i = 0; i < n; i++) {
          if (bit(mask, i) == 0)
            continue;
          double cost = mul[stage] * time[i];
          double new_dis = d + cost;
          State new_state = {mask ^ (1 << i), 0,
                             (stage + (int)floor(cost) % m) % m};
          if (dis.find(new_state) == dis.end() or new_dis < dis[new_state]) {
            dis[new_state] = new_dis;
            q.push({new_dis, new_state});
          }
        }
      }
    }

    double ans = DBL_MAX;
    for (int j = 0; j < m; j++) {
      State wanted = {(1 << n) - 1, 1, j};
      if (dis.find(wanted) != dis.end())
        umin(ans, dis[wanted]);
    }
    return ans == DBL_MAX ? -1 : ans;
  }
};

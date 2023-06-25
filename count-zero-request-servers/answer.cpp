template <class T>
vector<int> getOrderedIds(const vector<T> &v, function<bool(int, int)> comp) {
  int n = v.size();
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), comp);
  return p;
}

inline bool between(int l, int x, int r) { return l <= x && x <= r; }

class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &queries) {
    unordered_map<int, vector<int>> tm;
    for (auto &log : logs) {
      tm[log[0]].push_back(log[1]);
    }

    vector<pair<int, int>> received;
    // merge received ranges for each server
    for (auto [server, times] : tm) {
      sort(times.begin(), times.end());
      int k = times.size();

      stack<pair<int, int>> stk;
      stk.push({times[0], times[0] + x});
      for (int i = 1; i < k; i++) {
        auto &[l, r] = stk.top();
        if (between(l, times[i], r)) {
          r = max(r, times[i] + x);
        } else {
          stk.push({times[i], times[i] + x});
        }
      }
      while (!stk.empty()) {
        auto [l, r] = stk.top();
        stk.pop();
        received.push_back({l, 1});
        received.push_back({r + 1, -1});
      }
    }

    vector<int> qids = getOrderedIds(
        queries, [&](int lh, int rh) { return queries[lh] < queries[rh]; });
    int qn = queries.size();

    vector<int> ans(qn, -1);
    sort(received.begin(), received.end());
    int recn = received.size();
    for (int i = 0, sum = 0, j = 0; j < qn; j++) {
      int pos = queries[qids[j]];
      while (i < recn and received[i].first <= pos)
        sum += received[i++].second;
      ans[qids[j]] = n - sum;
    }
    return ans;
  }
};

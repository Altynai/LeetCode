#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

const int N = 26;

struct TopologicalSort {
  // order, {} means there is cycle
  vector<int> findOrder(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> deg(n, 0);
    for (int u = 0; u < n; u++) {
      for (int v : g[u]) {
        deg[v]++;
      }
    }

    deque<int> q;
    for (int u = 0; u < n; u++)
      if (deg[u] == 0)
        q.push_back(u);

    vector<int> ord(n, -1);
    int timestamp = 0;
    while (q.size()) {
      int u = q.front();
      q.pop_front();
      ord[u] = timestamp++;
      for (int v : g[u]) {
        if (--deg[v] == 0)
          q.push_back(v);
      }
    }

    // found cycle
    if (timestamp < n)
      return {};
    return ord;
  }
} topological_sort;

class Solution {
public:
  vector<vector<int>> supersequences(vector<string> &words) {
    vector<vector<bool>> bigram(N, vector<bool>(N, 0));
    set<int> seen;
    for (auto s : words) {
      int u = s[0] - 'a';
      int v = s[1] - 'a';
      bigram[u][v] = 1;
      seen.insert(u);
      seen.insert(v);
    }

    vector<int> uniq(seen.begin(), seen.end());
    int m = uniq.size();

    vector<pair<int, int>> masks(1 << m);
    for (int i = 0; i < (1 << m); i++)
      masks[i] = {bitCount(i), i};
    sort(masks.begin(), masks.end());

    vector<int> twice;
    for (int cnt = 0, i = 0; cnt <= m; cnt++) {

      vector<int> res;
      vector<vector<int>> adj(m);
      for (; i < masks.size() and masks[i].first == cnt; i++) {
        int mask = masks[i].second;
        adj.assign(m, vector<int>());

        for (int i = 0; i < m; i++) {
          if (bit(mask, i))
            continue;

          int u = uniq[i];
          for (int j = 0; j < m; j++) {
            int v = uniq[j];
            if (!bigram[u][v])
              continue;
            if (!bit(mask, j))
              adj[i].push_back(j);
          }
        }
        if (topological_sort.findOrder(adj).size() > 0)
          res.push_back(mask);
      }
      if (res.size() > 0) {
        twice = res;
        break;
      }
    }

    vector<vector<int>> ans;
    for (int mask : twice) {
      vector<int> res(N, 0);
      for (int x = 0; x < m; x++) {
        int y = uniq[x];
        res[y] = (bit(mask, x) ? 2 : 1);
      }
      ans.push_back(res);
    }
    return ans;
  }
};

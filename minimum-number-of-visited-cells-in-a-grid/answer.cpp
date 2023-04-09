template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

struct Node {
  min_priority_queue<pair<int, int>> que;
  multiset<int> weights;

  Node(){};

  void add(int pos, int weight) {
    que.push({pos, weight});
    weights.insert(weight);
  }

  int getMinWeight(int pos) {
    while (!que.empty() and pos > que.top().first) {
      auto [idx, w] = que.top();
      que.pop();
      weights.erase(weights.find(w));
    }
    return weights.empty() ? INT_MAX : *weights.begin();
  }
};

class Solution {
public:
  int minimumVisitedCells(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    if (n == 1 and m == 1)
      return 1;

    vector<Node> row(n), col(m);
    row[0].add(a[0][0], 1);
    col[0].add(a[0][0], 1);

    for (int i = 0; i < n; i++) {
      for (int j = (i == 0 ? 1 : 0); j < m; j++) {
        int best = min(row[i].getMinWeight(j), col[j].getMinWeight(i));
        if (best < INT_MAX) {
          best += 1;
          row[i].add(a[i][j] + j, best);
          col[j].add(a[i][j] + i, best);
        }
        if (i == n - 1 and j == m - 1)
          return (best == INT_MAX ? -1 : best);
      }
    }
    return -1;
  }
};

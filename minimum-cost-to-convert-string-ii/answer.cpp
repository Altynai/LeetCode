const int N = 26;

using int64 = long long;

template <class T> bool umin(T &a, const T b) {
  assert(b != -1);
  return (a == -1 or b < a) ? a = b, 1 : 0;
}

struct Node {
  int id;
  Node *children[N];

  Node() {
    id = -1;
    for (int i = 0; i < N; i++)
      children[i] = nullptr;
  }
};

class Solution {
public:
  long long minimumCost(string source, string target, vector<string> &original,
                        vector<string> &changed, vector<int> &cost) {
    int n = source.size();

    int m = 0;
    unordered_map<string, int> ids;
    for (string s : original) {
      if (ids.count(s) == 0)
        ids[s] = m++;
    }
    for (string s : changed) {
      if (ids.count(s) == 0)
        ids[s] = m++;
    }

    vector<vector<int>> dis(m, vector<int>(m, -1));
    int w = original.size();
    for (int i = 0; i < w; i++) {
      int x = ids[original[i]];
      int y = ids[changed[i]];
      umin(dis[x][y], cost[i]);
    }
    for (int k = 0; k < m; k++) {
      for (int i = 0; i < m; i++) {
        if (dis[i][k] == -1)
          continue;
        for (int j = 0; j < m; j++) {
          if (dis[k][j] == -1)
            continue;
          umin(dis[i][j], dis[i][k] + dis[k][j]);
        }
      }
    }

    Node *root = new Node();
    for (auto [s, id] : ids) {
      Node *cur = root;
      for (char ch : s) {
        int pos = ch - 'a';
        if (cur->children[pos] == nullptr)
          cur->children[pos] = new Node();
        cur = cur->children[pos];
      }
      cur->id = id;
    }
    vector<int64> dp(n + 1, -1);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      Node *s = root, *t = root;
      bool same = 1;
      for (int j = i; j < n; j++) {
        // same char
        if (source[j] != target[j])
          same = 0;
        if (same and dp[j + 1] != -1) {
          umin(dp[i], dp[j + 1]);
        }

        // different char
        int spos = source[j] - 'a';
        int tpos = target[j] - 'a';
        if (s != nullptr and t != nullptr) {
          s = s->children[spos];
          t = t->children[tpos];
          if (s != nullptr and t != nullptr and s->id != -1 and t->id != -1 and
              dis[s->id][t->id] != -1 and dp[j + 1] != -1) {
            umin(dp[i], dp[j + 1] + dis[s->id][t->id]);
          }
        }
      }
    }
    return dp[0];
  }
};

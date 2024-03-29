const int N = 26;

struct Node {
  Node *nxt[N];
  int best;

  Node() {
    for (int i = 0; i < N; i++)
      nxt[i] = nullptr;
    best = -1;
  };
};

class Solution {
public:
  vector<int> stringIndices(vector<string> &wordsContainer,
                            vector<string> &wordsQuery) {
    Node *root = new Node();

    auto Update = [&](int &x, int y) {
      if (x == -1)
        x = y;
      else if (wordsContainer[y].size() < wordsContainer[x].size())
        x = y;
      else if (wordsContainer[y].size() == wordsContainer[x].size() and y < x)
        x = y;
    };

    int n = wordsContainer.size();
    for (int i = 0; i < n; i++) {
      Node *cur = root;
      int len = wordsContainer[i].size();
      for (int j = len - 1; j >= 0; j--) {
        int id = wordsContainer[i][j] - 'a';
        if (cur->nxt[id] == nullptr)
          cur->nxt[id] = new Node();
        cur = cur->nxt[id];
        Update(cur->best, i);
      }
    }

    int p = 0;
    for (int i = 1; i < n; i++) {
      if (wordsContainer[i].size() < wordsContainer[p].size())
        p = i;
    }

    int m = wordsQuery.size();
    vector<int> ans(m, p);
    for (int i = 0; i < m; i++) {
      Node *cur = root;
      int len = wordsQuery[i].size();
      for (int j = len - 1; j >= 0; j--) {
        int id = wordsQuery[i][j] - 'a';
        if (cur->nxt[id] == nullptr)
          break;
        cur = cur->nxt[id];
      }
      // empty suffix has been handled with defalut value
      if (cur != root)
        ans[i] = cur->best;
    }
    return ans;
  }
};

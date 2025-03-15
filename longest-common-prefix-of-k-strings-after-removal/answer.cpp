
template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

struct Trie {

  static const int N = 26;

  Trie *children[N];
  int val = 0, best = -1;

  Trie() {
    for (int i = 0; i < N; i++)
      children[i] = nullptr;
    val = 0;
    best = -1;
  }

  void insert(Trie *cur, const string &s, int pos, int val) {
    cur->best = -1;
    int n = s.size();
    if (pos == n) {
      return;
    } else {
      int b = s[pos] - 'a';
      if (cur->children[b] == nullptr)
        cur->children[b] = new Trie();

      cur->children[b]->val += val;
      insert(cur->children[b], s, pos + 1, val);
    }
  }

  int query(Trie *cur, int k) {
    if (cur->best != -1)
      return cur->best;

    int res = 0;
    for (int i = 0; i < N; i++) {
      Trie *nxt = cur->children[i];
      if (nxt != nullptr and nxt->val >= k) {
        umax(res, query(nxt, k) + 1);
      }
    }
    return cur->best = res;
  }
};

class Solution {
public:
  vector<int> longestCommonPrefix(vector<string> &words, int k) {
    int n = words.size();

    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
      t->insert(t, words[i], 0, +1);

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      t->insert(t, words[i], 0, -1);
      umax(ans[i], t->query(t, k));
      t->insert(t, words[i], 0, +1);
    }
    return ans;
  }
};

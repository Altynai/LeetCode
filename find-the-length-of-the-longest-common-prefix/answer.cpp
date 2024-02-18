const int N = 10;

struct Trie {
  vector<Trie *> nxt;

  Trie() { nxt = vector<Trie *>(N, nullptr); }
};

class Solution {
private:
  void insert(Trie *root, const string &s) {
    Trie *cur = root;
    for (char ch : s) {
      int pos = ch - '0';
      if (cur->nxt[pos] == nullptr)
        cur->nxt[pos] = new Trie();
      cur = cur->nxt[pos];
    }
  }

public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    Trie *root1 = new Trie(), *root2 = new Trie();
    for (int x : arr1)
      insert(root1, to_string(x));
    for (int x : arr2)
      insert(root2, to_string(x));

    int ans = 0;
    function<void(Trie *, Trie *, int)> dfs = [&](Trie *x, Trie *y, int len) {
      ans = max(ans, len);
      for (int i = 0; i < N; i++) {
        if (x->nxt[i] != nullptr and y->nxt[i] != nullptr)
          dfs(x->nxt[i], y->nxt[i], len + 1);
      }
    };
    dfs(root1, root2, 0);
    return ans;
  }
};

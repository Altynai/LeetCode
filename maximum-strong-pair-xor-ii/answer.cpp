const int N = 20;

// trie node
struct Node {
  Node *nxt[2];
  int cnt;

  Node() {
    nxt[0] = nxt[1] = nullptr;
    cnt = 0;
  }
};

class Solution {
public:
  int maximumStrongPairXor(vector<int> &a) {
    Node *root = new Node();

    auto Update = [&](int x, int c) {
      Node *cur = root;
      for (int i = N - 1; i >= 0; i--) {
        int pos = (x & (1 << i)) > 0 ? 1 : 0;
        if (cur->nxt[pos] == nullptr)
          cur->nxt[pos] = new Node();
        cur = cur->nxt[pos];
        cur->cnt += c;
      }
    };

    auto Query = [&](int x) -> int {
      Node *cur = root;
      int ans = 0;
      for (int i = N - 1; i >= 0; i--) {
        int pos = (x & (1 << i)) > 0 ? 1 : 0;
        int best = pos ^ 1;
        if (cur->nxt[best] == nullptr or cur->nxt[best]->cnt == 0)
          best = pos;
        cur = cur->nxt[best];
        if (best != pos)
          ans |= (1 << i);
      }
      return ans;
    };

    int n = a.size(), ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0, j = 0; i < n; i++) {
      while (j < n and a[j] <= a[i] * 2)
        Update(a[j++], +1);
      ans = max(ans, Query(a[i]));
      Update(a[i], -1);
    }
    return ans;
  }
};

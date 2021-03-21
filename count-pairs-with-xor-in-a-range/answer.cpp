#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))
// =====================================================================================================================

struct Node {
  Node *nxt[2];
  int sz;
  Node() {
    nxt[0] = nxt[1] = NULL;
    sz = 0;
  }
};

const int N = 15;

void insert(Node *root, int val) {
  for (int i = N - 1; i >= 0; i--) {
    int pos = bit(val, i);
    if (root->nxt[pos] == NULL)
      root->nxt[pos] = new Node();
    root = root->nxt[pos];
    root->sz++;
  }
}

int query(Node *root, int val, int limit) {
  int ans = 0;
  for (int i = N - 1; root && i >= 0; i--) {
    int valBit = bit(val, i);
    int limitBit = bit(limit, i);

    if (valBit) {
      // val:   1
      // limit: 1
      if (limitBit) {
        if (root->nxt[1])
          ans += root->nxt[1]->sz;
        root = root->nxt[0];
      } else {
        // val:   1
        // limit: 0
        root = root->nxt[1];
      }
    } else {
      // val:   0
      // limit: 1
      if (limitBit) {
        if (root->nxt[0])
          ans += root->nxt[0]->sz;
        root = root->nxt[1];
      } else {
        // val:   0
        // limit: 0
        root = root->nxt[0];
      }
    }
  }
  return ans;
}

class Solution {
public:
  int countPairs(vector<int> &nums, int low, int high) {
    int n = nums.size();
    Node *root = new Node();
    insert(root, nums[0]);

    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += query(root, nums[i], high + 1) - query(root, nums[i], low);
      insert(root, nums[i]);
    }
    return ans;
  }
};

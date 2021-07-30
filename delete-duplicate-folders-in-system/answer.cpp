struct Node {
  map<string, Node *> children;
  bool alive;

  Node() {
    alive = 1;
    children.clear();
  }

  bool contains(const string &s) { return children.count(s) > 0; }
};

class Solution {
public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
    Node *root = new Node();
    for (auto &path : paths) {
      Node *r = root;
      for (string &s : path) {
        if (!r->contains(s)) {
          r->children[s] = new Node();
        }
        r = r->children[s];
      }
    }

    map<string, Node *> seen;
    function<string(Node *, const string &)> dfs =
        [&](Node *r, const string &s) -> string {
      if (r->children.empty())
        return s;

      string t;
      for (auto [k, v] : r->children) {
        t += "(" + dfs(v, k) + ")";
      }
      auto it = seen.find(t);
      if (it != seen.end()) {
        it->second->alive = 0;
        r->alive = 0;
      } else {
        seen[t] = r;
      }
      return t + s;
    };

    dfs(root, "/");

    vector<vector<string>> ans;
    vector<string> stack;
    function<void(Node *)> dfs2 = [&](Node *r) {
      for (auto [k, v] : r->children) {
        if (v->alive == 1) {
          stack.emplace_back(k);
          ans.push_back(stack);
          dfs2(v);
          stack.pop_back();
        }
      }
    };
    dfs2(root);

    return ans;
  }
};

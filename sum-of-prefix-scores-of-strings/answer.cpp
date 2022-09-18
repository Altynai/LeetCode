struct Trie {

  static const int N = 26;

  Trie *children[N];
  int val = 0;

  Trie() {
    for (int i = 0; i < N; i++)
      children[i] = nullptr;
    val = 0;
  }

  Trie *insert(const string &s) {
    Trie *cur = this;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int b = s[i] - 'a';
      if (cur->children[b] == nullptr)
        cur->children[b] = new Trie();
      cur = cur->children[b];
      cur->val += 1;
    }
    return cur;
  }

  int query(const string &s) {
    Trie *cur = this;
    int n = s.size(), sum = 0;
    for (int i = 0; i < n; i++) {
      int b = s[i] - 'a';
      cur = cur->children[b];
      sum += cur->val;
    }
    return sum;
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string> &words) {
    Trie *root = new Trie();
    for (string &word : words)
      root->insert(word);

    int n = words.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = root->query(words[i]);
    return ans;
  }
};

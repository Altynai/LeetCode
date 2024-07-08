template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

struct Trie {

  static const int N = 26;

  Trie *children[N];
  int val;

  Trie() {
    for (int i = 0; i < N; i++)
      children[i] = nullptr;
    val = INT_MAX;
  }

  Trie *insert(const string &s, int val) {
    Trie *cur = this;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int b = s[i] - 'a';
      if (cur->children[b] == nullptr)
        cur->children[b] = new Trie();
      cur = cur->children[b];
    }
    cur->val = min(cur->val, val);
    return cur;
  }
};

/*
https://oi-wiki.org/string/z-func/

z[i] = LCP(s, s[i, n - 1]), especially: z[0] = 0

z(aaaaa) = [0, 4, 3, 2, 1]
z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
*/
vector<int> z_function(const string &s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
    }
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

const int N = 300; // sqrt of length

class Solution {
public:
  int minimumCost(string target, vector<string> &words, vector<int> &costs) {
    /*
    rough idea O(N sqrtN): dp and speed up the transition with:
      * for shorter words: trie
      * for longer words: z function
    */

    int n = target.size();

    Trie *root = new Trie();
    vector<int> longer;
    for (int i = 0; i < words.size(); i++) {
      if (words[i].size() < N)
        root->insert(words[i], costs[i]);
      else
        longer.push_back(i);
    }

    int m = longer.size();
    vector<vector<int>> zs(m);
    for (int i = 0; i < m; i++) {
      string t = words[longer[i]] + "#" + target;
      zs[i] = z_function(t);
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      if (dp[i] == INT_MAX)
        continue;

      // handle shorter words
      Trie *cur = root;
      int j = i + 1;
      while (j <= n and cur != nullptr and
             cur->children[target[j - 1] - 'a'] != nullptr) {
        cur = cur->children[target[j - 1] - 'a'];
        if (cur->val != INT_MAX)
          umin(dp[j], dp[i] + cur->val);
        j++;
      }

      // handle longer words
      for (int k = 0; k < m; k++) {
        const string &word = words[longer[k]];
        const vector<int> &z = zs[k];
        int len = word.size();
        if (z[len + 1 + i] == len) {
          j = i + len;
          umin(dp[j], dp[i] + costs[longer[k]]);
        }
      }
    }
    return dp[n] == INT_MAX ? -1 : dp[n];
  }
};

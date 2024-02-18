using int64 = long long;

const int N = 26;

struct Trie {
  vector<Trie *> nxt;
  int freq;

  Trie() { nxt = vector<Trie *>(N, nullptr), freq = 0; }
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

class Solution {
public:
  long long countPrefixSuffixPairs(vector<string> &s) {
    int n = s.size();
    Trie *root = new Trie();

    int64 ans = 0;
    auto Count = [&](const string &t) -> int {
      Trie *cur = root;
      for (char ch : t) {
        int pos = ch - 'a';
        if (cur->nxt[pos] == nullptr)
          return 0;
        cur = cur->nxt[pos];
      }
      return cur->freq;
    };

    for (int i = n - 1; i >= 0; i--) {
      ans += Count(s[i]);

      int m = s[i].size();
      vector<int> z = z_function(s[i]);
      Trie *cur = root;
      for (int j = 0; j < m; j++) {
        int pos = s[i][j] - 'a';
        if (cur->nxt[pos] == nullptr)
          cur->nxt[pos] = new Trie();
        cur = cur->nxt[pos];

        // for each string t with length m
        // we can add pair {t.substr(0, k), +1} to the Trie if t.substr(0, k) ==
        // t.substr(m - k)
        if (j < m - 1) {
          if (z[m - 1 - j] == j + 1)
            cur->freq++;
        } else {
          // entire string is always good
          cur->freq++;
        }
      }
    }
    return ans;
  }
};

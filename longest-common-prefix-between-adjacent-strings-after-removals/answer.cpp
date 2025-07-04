template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int lcp(const string &s, const string &t) {
    int n = s.size(), m = t.size();
    for (int i = 0; i < min(n, m); i++) {
      if (s[i] != t[i])
        return i;
    }
    return min(n, m);
  }

  vector<int> longestCommonPrefix(vector<string> &words) {
    int n = words.size();
    vector<int> vals(n, -1);
    for (int i = 0; i < n - 1; i++)
      vals[i] = lcp(words[i], words[i + 1]);

    vector<int> pfx(n, -1), sfx(n, -1);
    for (int i = 1; i < n; i++) {
      pfx[i] = vals[i - 1];
      if (i > 1)
        umax(pfx[i], pfx[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      sfx[i] = vals[i];
      if (i < n - 2)
        umax(sfx[i], sfx[i + 1]);
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      if (i >= 2)
        umax(ans[i], pfx[i - 1]);
      if (i <= n - 3)
        umax(ans[i], sfx[i + 1]);
      if (i > 0 and i < n - 1)
        umax(ans[i], lcp(words[i - 1], words[i + 1]));
    }
    return ans;
  }
};

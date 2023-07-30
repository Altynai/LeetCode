class Solution {
private:
  int lcs(const string &a, const string &b) {
    int n = min(a.size(), b.size());
    for (int k = n; k >= 1; k--) {
      string x = a.substr(a.size() - k);
      string y = b.substr(0, k);
      if (x == y)
        return k;
    }
    return 0;
  }

  void update(string &a, const string &b) {
    if (b.size() < a.size() || (b.size() == a.size() and b < a))
      a = b;
  }

public:
  string minimumString(string a, string b, string c) {
    vector<string> s = {a, b, c};
    vector<int> p = {0, 1, 2};

    string ans = a + b + c;
    do {
      vector<string> cand = {s[p[0]]};
      for (int i = 1; i <= 2; i++) {
        vector<string> nxt;
        for (auto &t : cand) {
          // concat
          int k = lcs(t, s[p[i]]);
          nxt.push_back(t + s[p[i]].substr(k));
          // substr
          if (t.find(s[p[i]]) != -1)
            nxt.push_back(t);
        }
        swap(cand, nxt);
      }
      for (auto &t : cand)
        update(ans, t);
    } while (next_permutation(p.begin(), p.end()));
    return ans;
  }
};

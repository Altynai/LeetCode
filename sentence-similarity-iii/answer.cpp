class Solution {
public:
  bool areSentencesSimilar(string s1, string s2) {
    auto split = [&](string s) {
      vector<string> ans;
      stringstream ss(s);
      string token;
      while (ss >> token)
        ans.push_back(token);
      return ans;
    };

    vector<string> a = split(s1), b = split(s2);
    if (a.size() > b.size())
      swap(a, b);

    int n = a.size(), m = b.size();
    if (n == m)
      return a == b;

    for (int i = 0; i < n; i++) {
      // a[i - 1], xxxx, a[i], ...
      // b[0], b[1], b[2], ....
      vector<string> c(b.begin(), b.begin() + i);

      int k = n - i;
      c.insert(c.end(), b.begin() + m - k, b.end());
      if (a == c)
        return 1;
    }

    return vector<string>(b.begin(), b.begin() + n) == a;
  }
};

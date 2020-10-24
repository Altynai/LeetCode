class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    string ans = s;
    int n = s.size();
    b %= n;

    deque<string> q;
    unordered_set<string> seen;

    q.push_back(s);
    seen.insert(s);

    while (!q.empty()) {
      string t = q.front();
      q.pop_front();

      // rotate
      string t2 = t.substr(n - b) + t.substr(0, n - b);
      if (seen.count(t2) == 0) {
        q.push_back(t2);
        seen.insert(t2);
      }
      ans = min(ans, t2);

      // add
      for (int i = 1; i < n; i += 2) {
        t[i] += a;
        if (t[i] > '9')
          t[i] -= 10;
      }
      if (seen.count(t) == 0) {
        q.push_back(t);
        seen.insert(t);
      }
      ans = min(ans, t);
    }
    return ans;
  }
};

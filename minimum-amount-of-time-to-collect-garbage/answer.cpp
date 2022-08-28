class Solution {
public:
  int garbageCollection(vector<string> &g, vector<int> &t) {
    string s = "MPG";
    int ans = 0, n = g.size();
    for (char ch : s) {
      int cnt = 0;
      for (string &x : g)
        cnt += count(x.begin(), x.end(), ch);

      for (int i = 0; cnt > 0 and i < n; i++) {
        if (i)
          ans += t[i - 1];
        int x = count(g[i].begin(), g[i].end(), ch);
        ans += x;
        cnt -= x;
      }
    }
    return ans;
  }
};

class Solution {
public:
  int longestBeautifulSubstring(string s) {
    int n = s.size();
    vector<pair<int, int>> g(1, make_pair(s[0], 1));
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1])
        g.back().second += 1;
      else
        g.emplace_back(s[i], 1);
    }

    int ans = 0, m = g.size();
    for (int i = 0; i + 4 < m; i++) {
      string order = "aeiou";
      int j = 0, sum = 0;
      for (; j < 5; j++) {
        if (g[i + j].first != order[j])
          break;
        sum += g[i + j].second;
      }
      if (j == 5)
        ans = max(ans, sum);
    }
    return ans;
  }
};

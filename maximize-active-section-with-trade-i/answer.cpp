class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    // 1..10..0110..01..1
    // 1..10..0000..01..1
    // 1..11..1111..11..1
    // we need to check groups of 1, 0, 1, 0, 1

    int n = s.size();

    vector<pair<int, int>> g;
    int ans = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and s[j] == s[i])
        j++;
      g.push_back({s[i] - '0', j - i});
      if (s[i] == '1')
        ans += j - i;
      i = j;
    }

    int m = g.size(), gain = 0;
    for (int i = (g[0].first == 0 ? 0 : 1); i + 2 < m; i += 2) {
      gain = max(gain, g[i].second + g[i + 2].second);
    }
    return ans + gain;
  }
};

const int N = 256;

class Solution {
public:
  bool matchReplacement(string s, string sub, vector<vector<char>> &mappings) {
    vector<vector<bool>> ok(N, vector<bool>(N, 0));
    for (auto &mp : mappings)
      ok[mp[0]][mp[1]] = 1;

    int n = s.size(), m = sub.size();
    for (int i = 0; i + m - 1 < n; i++) {
      bool match = 1;
      for (int j = 0; match and j < m; j++) {
        if (sub[j] != s[i + j] and !ok[sub[j]][s[i + j]])
          match = 0;
      }
      if (match)
        return 1;
    }
    return 0;
  }
};

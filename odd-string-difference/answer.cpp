class Solution {
public:
  string oddString(vector<string> &w) {
    int n = w.size();
    map<vector<int>, int> cnt;
    map<vector<int>, string> s;

    for (int i = 0; i < n; i++) {
      int m = w[i].size();
      vector<int> a;
      for (int j = 0; j < m - 1; j++)
        a.push_back(w[i][j + 1] - w[i][j]);
      cnt[a]++;
      s[a] = w[i];
    }
    for (auto [k, v] : cnt) {
      if (v == 1)
        return s[k];
    }
    return "";
  }
};

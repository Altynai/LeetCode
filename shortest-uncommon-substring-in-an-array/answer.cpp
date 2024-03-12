class Solution {
public:
  vector<string> shortestSubstrings(vector<string> &arr) {
    unordered_map<string, int> cnt;

    auto Update = [&](const string &t, int val) {
      int m = t.size();
      for (int j = 0; j < m; j++) {
        string s;
        for (int k = j; k < m; k++) {
          s.push_back(t[k]);
          cnt[s] += val;
        }
      }
    };

    auto Check = [&](const string &t) -> bool {
      auto it = cnt.find(t);
      return it == cnt.end() or it->second == 0;
    };

    int n = arr.size();
    for (int i = 0; i < n; i++)
      Update(arr[i], 1);

    vector<string> ans(n, "");
    for (int i = 0; i < n; i++) {
      Update(arr[i], -1);

      int m = arr[i].size();
      for (int j = 0; j < m; j++) {
        string s;
        for (int k = j; k < m; k++) {
          s.push_back(arr[i][k]);
          if (Check(s)) {
            if (ans[i] == "" or s.size() < ans[i].size() or
                (s.size() == ans[i].size() and s < ans[i]))
              ans[i] = s;
          }
        }
      }

      Update(arr[i], 1);
    }
    return ans;
  }
};

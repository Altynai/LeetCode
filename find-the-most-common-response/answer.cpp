class Solution {
public:
  string findCommonResponse(vector<vector<string>> &responses) {
    int n = responses.size();
    unordered_map<string, int> cnt;
    for (int i = 0; i < n; i++) {
      unordered_set<string> s(responses[i].begin(), responses[i].end());
      for (string str : s)
        cnt[str]++;
    }

    string best = cnt.begin()->first;
    int ans = cnt.begin()->second;
    for (auto [k, v] : cnt) {
      if (v > ans or (v == ans and k < best)) {
        best = k;
        ans = v;
      }
    }
    return best;
  }
};

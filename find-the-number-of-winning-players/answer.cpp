const int N = 10;
class Solution {
public:
  int winningPlayerCount(int n, vector<vector<int>> &pick) {
    vector<vector<int>> cnt(n, vector<int>(N + 1, 0));
    for (auto v : pick)
      cnt[v[0]][v[1]]++;

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (*max_element(cnt[i].begin(), cnt[i].end()) >= i + 1)
        ans++;
    }
    return ans;
  }
};

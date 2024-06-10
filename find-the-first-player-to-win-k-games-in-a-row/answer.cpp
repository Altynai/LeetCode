class Solution {
public:
  int findWinningPlayer(vector<int> &s, int k) {
    int n = s.size(), winner = 0;
    unordered_map<int, int> cnt;

    for (int i = 1; i < n; i++) {
      if (s[i] > s[winner])
        cnt[winner = i]++;
      else
        cnt[winner]++;
      if (cnt[winner] == k)
        return winner;
    }
    return winner;
  }
};

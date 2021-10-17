class Solution {
public:
  bool winnerOfGame(string s) {
    int n = s.size();
    vector<int> cnt(2, 0);
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && s[j] == s[i])
        j++;
      cnt[s[i] - 'A'] += max(0, j - i - 2);
      i = j;
    }
    return cnt[0] >= cnt[1] + 1;
  }
};

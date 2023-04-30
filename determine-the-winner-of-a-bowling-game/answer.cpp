class Solution {
private:
  int score(const vector<int> &p) {
    int ans = 0, n = p.size();
    for (int i = 0; i < n; i++) {
      int t = 1;
      if (i >= 1 and p[i - 1] == 10)
        t = 2;
      if (i >= 2 and p[i - 2] == 10)
        t = 2;
      ans += p[i] * t;
    }
    return ans;
  }

public:
  int isWinner(vector<int> &player1, vector<int> &player2) {
    int x = score(player1);
    int y = score(player2);
    if (x == y)
      return 0;
    return x > y ? 1 : 2;
  }
};

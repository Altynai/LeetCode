class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int ans = 0, pre = 0;
    for (string &row : bank) {
      int now = count(row.begin(), row.end(), '1');
      if (now == 0)
        continue;

      ans += pre * now;
      pre = now;
    }
    return ans;
  }
};

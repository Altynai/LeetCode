const int N = 26;

class Solution {
public:
  string getSmallestString(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int choose = -1;
      for (int j = 0; j < N; j++) {
        int d = abs(s[i] - 'a' - j);
        d = min(d, N - d);
        if (d <= k) {
          choose = j;
          k -= d;
          break;
        }
      }
      assert(choose != -1);
      s[i] = 'a' + choose;
    }
    return s;
  }
};

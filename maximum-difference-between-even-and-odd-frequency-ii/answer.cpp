// functions
template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

const int N = 3e4 + 7;

class Solution {
private:
  int mins[N][2][2];

  int maxDifference(const string &s, int a, int b, int k) {
    int n = s.size();
    mins[0][0][1] = mins[0][1][1] = mins[0][1][0] = INT_MAX;
    mins[0][0][0] = 0;

    int cnta = 0, cntb = 0, ans = INT_MIN;
    int lasta = -1, lastb = -1;
    for (int i = 1; i <= n; i++) {

      // copy
      for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
          mins[i][x][y] = mins[i - 1][x][y];

      int digit = s[i - 1] - '0';
      if (digit == a)
        cnta++, lasta = i;
      else if (digit == b)
        cntb++, lastb = i;

      int delta = cnta - cntb;
      int paritya = cnta % 2, parityb = cntb % 2;
      umin(mins[i][paritya][parityb], delta);

      if (cnta > 0 and cntb > 0) {
        int pos = min(i - k, min(lasta, lastb) - 1);
        if (pos >= 0 and mins[pos][paritya ^ 1][parityb] != INT_MAX)
          umax(ans, delta - mins[pos][paritya ^ 1][parityb]);
      }
    }
    return ans;
  }

public:
  int maxDifference(string s, int k) {
    vector<bool> seen(5, 0);
    for (char ch : s)
      seen[ch - '0'] = 1;

    int ans = INT_MIN;
    for (int a = 0; a < 5; a++) {
      if (!seen[a])
        continue;
      for (int b = 0; b < 5; b++) {
        if (!seen[b] or a == b)
          continue;
        umax(ans, maxDifference(s, a, b, k));
      }
    }
    return ans;
  }
};

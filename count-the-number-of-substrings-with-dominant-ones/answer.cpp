const int N = 200;

class Solution {
public:
  int numberOfSubstrings(string s) {
    // n <= 4 * 10^4 gives a hint of maybe "N * sqrt(N)"
    // we can also enumerate the number of zero-s
    int n = s.size();
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        pos.push_back(i);
    }

    int ans = 0, m = pos.size();
    for (int i = 0, j = 0; i < n; i++) {
      // find first pos[j] >= i
      while (j < m and pos[j] < i)
        j++;

      // no zero
      if (s[i] == '1')
        ans += (j == m ? n : pos[j]) - i;

      // contains p 0's
      for (int p = 1; p <= min(N, m - j); p++) {
        int k = pos[j + p - 1];
        // s[i ... j ..... k .... nxt_zero]
        //         0 ..... 0 1111 0
        //           p 0's
        int min_len = p * p + p;
        int min_start_pos = max(k, i + min_len - 1);
        int nxt_zero = (j + p < m ? pos[j + p] : n);
        if (min_start_pos < nxt_zero)
          ans += nxt_zero - min_start_pos;
      }
    }
    return ans;
  }
};

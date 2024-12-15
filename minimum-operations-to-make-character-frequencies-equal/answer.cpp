template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

const int N = 26;

class Solution {
public:
  int makeStringGood(string s) {
    // 3rd operation can only be used for adjacent char and once, why?
    // 'a' -> 'b' -> 'c' is same as adding 'c' and delete 'a'

    // can we enumerate the times c?
    // occurrence of each char should be 0 or c in the end
    // if the previous char has some left over, we can use them with 3rd
    // operation

    int n = s.size();
    vector<int> freq(N, 0);
    for (char ch : s)
      freq[ch - 'a']++;

    int ans = INT_MAX;
    for (int cnt = 1; cnt <= n; cnt++) {
      // dp[0]: deleted some previous char and get some for `leftover`
      // dp[1]: previous char is added up to c, hence no `leftover` can be used
      // in this case
      vector<int> dp(2, 0);
      int leftover = 0;

      for (int ch = 0; ch < N; ch++) {
        vector<int> ndp(2, INT_MAX);
        int nleftover = 0;

        if (freq[ch] >= cnt) {
          ndp[0] = min(dp[0], dp[1]) + (freq[ch] - cnt);
          nleftover = freq[ch] - cnt;
        } else {
          int gap = cnt - freq[ch];
          ndp[0] = min(dp[0], dp[1]) + freq[ch];
          ndp[1] = dp[0] + max(gap - leftover, 0);
          if (dp[1] != INT_MAX)
            umin(ndp[1], dp[1] + gap);
          nleftover = freq[ch];
        }
        swap(dp, ndp);
        swap(leftover, nleftover);
      }
      umin(ans, min(dp[0], dp[1]));
    }
    return ans;
  }
};

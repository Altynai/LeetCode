const int N = 26;

class Solution {
public:
  int numberOfSpecialChars(string s) {
    int n = s.size();
    vector<bool> low(N, 0), up(N, 0);
    for (int i = 0; i < n; i++) {
      if (islower(s[i]))
        low[s[i] - 'a'] = 1;
      else
        up[s[i] - 'A'] = 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
      ans += int(low[i] and up[i]);
    return ans;
  }
};

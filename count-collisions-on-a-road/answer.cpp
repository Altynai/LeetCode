class Solution {
public:
  int countCollisions(string s) {
    int n = s.size(), ans = 0;
    for (int i = 1; i < n; i++) {
      if (s[i - 1] == 'R' and s[i] == 'L') {
        s[i - 1] = s[i] = 'S';
        ans += 2;
      }
    }

    vector<bool> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
      suff[i] = suff[i + 1] or (s[i] == 'S');

    bool pref = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L' and pref)
        ans++;
      else if (s[i] == 'R' and suff[i + 1])
        ans++;

      if (s[i] == 'S')
        pref = 1;
    }
    return ans;
  }
};
